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
    Sockets.first = nullptr;
    Sockets.second = nullptr;
}

// этот метод - переписанный метод виртуального класса QTcpServer
void Server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    if (Sockets.first == nullptr)
    {
        Sockets.first = socket;
        qDebug() << "First client connected";
        SendToClient1("CLIENT_1");
    } else if (Sockets.second == nullptr)
    {
        Sockets.second = socket;
        qDebug() << "Second client connected";
        SendToClient2("CLIENT_2");
    } else
    {
        qDebug() << "Two clients already connected";
        socket->disconnectFromHost();
        socket->deleteLater();
    }
}

//этот метод вычитывает строку из сокета и вызывет метод SendToClient(QString)
void Server::slotReadyRead()
{
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_9);
    if (in.status() == QDataStream::Ok)
    {
        qDebug() << "read...";
        QString str;
        in >> str;
        qDebug() << str;
        if (Sockets.first == socket)
        {
            SendToClient2(str);
        }
        else if (Sockets.second == socket)
        {
            SendToClient1(str);
        }
    }
    else
    {
        qDebug() << "DataStream error";
    }
}

// эти методы отправляют данные клиентам
void Server::SendToClient1(QString str)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out << str;
    Sockets.first->write(Data);
}

void Server::SendToClient2(QString str)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out << str;
    Sockets.second->write(Data);
}

