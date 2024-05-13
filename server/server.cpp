#include "server.h"

Server::Server()
{
    if (this->listen(QHostAddress::Any, PORT))
    {
        qDebug() << "start";
    }
    else
    {
        qDebug() << "error";
    }
}

Server::~Server()
{
    foreach (ClientThread *thread, clientThreads) {
        thread->terminate();
        thread->wait();
        delete thread;
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket *socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    if (Sockets.first == nullptr)
    {
        Sockets.first = socket;
        qDebug() << "First client connected";
        ClientThread *thread = new ClientThread(socket, &Sockets, this);
        thread->start();
        clientThreads.append(thread);
    } else if (Sockets.second == nullptr)
    {
        Sockets.second = socket;
        qDebug() << "Second client connected";
        ClientThread *thread = new ClientThread(socket, &Sockets, this);
        thread->start();
        clientThreads.append(thread);
    } else
    {
        qDebug() << "Two clients already connected, adding third client to waiting queue";
        waitingClients.enqueue(socket);
    }
}

void Server::slotReadyRead()
{
    QTcpSocket *socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_9);
    if (in.status() == QDataStream::Ok)
    {
        QString str;
        in >> str;
        qDebug() << str;
        if (Sockets.first == socket)
        {
            emit SendToClient2(str);
            qDebug() << "Got " << str <<" from second to first client";
        }
        else if (Sockets.second == socket)
        {
            emit SendToClient1(str);
            qDebug() << "Got " << str <<" from first to second client";
        }
    }
    else
    {
        qDebug() << "DataStream error";
    }
}

void Server::SendToClient1(const QString &message)
{
    if (Sockets.first) {
        QByteArray data;
        QDataStream stream(&data, QIODevice::WriteOnly);
        stream.setVersion(QDataStream::Qt_5_9);
        stream << message;
        Sockets.first->write(data);
    }
}
void Server::SendToClient2(const QString &message)
{
    if (Sockets.second) {
        QByteArray data;
        QDataStream stream(&data, QIODevice::WriteOnly);
        stream.setVersion(QDataStream::Qt_5_9);
        stream << message;
        Sockets.second->write(data);
    }
}

ClientThread::ClientThread(QTcpSocket *socket, QPair<QTcpSocket*, QTcpSocket*> *sockets, Server *server, QObject *parent)
    : QThread(parent), socket(socket), sockets(sockets), server(server)
{
}

void ClientThread::run()
{
    connect(socket, &QTcpSocket::readyRead, server, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    exec();
}
