#include "client.h"

void Client::SendToServer(QString str)
{
    // QString str = QString::number(num) + " " + QString::number(nc);
    qDebug() << "sended: " << str;
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out << str;
    socket->write(Data);
}

Client::Client()
{
    socket = new QTcpSocket();
    connect(socket, &QTcpSocket::readyRead, this, &Client::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    socket->connectToHost("127.0.0.1", 2323);
}

void Client::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_9);
    QString str;
    if(in.status() == QDataStream::Ok)
    {
        in >> str;
    }
    data << str;
}
