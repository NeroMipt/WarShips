#include "server.h"

Server::Server(QObject *parent) : QTcpServer(parent)
{
    connect(this, &QTcpServer::newConnection, this, &Server::onNewConnection);
    if (this->listen(QHostAddress::Any, PORT)) {
        qDebug() << "Server is listening on port" << PORT;
    } else {
        qDebug() << "Failed to start the server";
    }
}

void Server::onNewConnection()
{
    QTcpSocket *socket = nextPendingConnection();
    clients.append(socket);
    connect(socket, &QTcpSocket::disconnected, this, &Server::onDisconnected);
    qDebug() << "New connection" << clients;
    if (clients.size() >= 2) {
        QThread *thread = new QThread();
        threads.append(thread);
        ClientThread *clientThread = new ClientThread(clients.takeFirst(), clients.takeFirst());
        clientThread->moveToThread(thread);
        connect(thread, &QThread::started, clientThread, &ClientThread::run);
        thread->start();
    }
}


void Server::onDisconnected()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    qDebug() << "client " << socket << "is disconnected\n";
    clients.removeAll(socket);
    socket->deleteLater();
}
