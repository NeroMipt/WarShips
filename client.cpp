#include "client.h"

void Client::SendToServer(int num, int nc)
{
    qDebug() << "here";
    QString str = QString::number(num) + " " + QString::number(nc);
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out << str;
    socket->write(Data);
}

void Client::connection(QString address)
{
    socket->connectToHost(address, 2323);
}

Client::Client()
{
    socket = new QTcpSocket();
    connect(socket, &QTcpSocket::readyRead, this, &Client::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
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
    QStringList list = str.split(' ');
    int command = list[0].toInt();
    int nc      = list[1].toInt();
    switch(command){
    case 1:{
        emit attacked(nc);
    }
    case -3:{
        emit responseDamage(nc);
    }
    case -4:{
        emit responseNonDamage(nc);
    }
    case -5:
        emit responseWin();
    }
}
