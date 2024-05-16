#include "client.h"

void Client::SendToServer(int num, int nc)
{
    QString str = QString::number(num) + " " + QString::number(nc);
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out << str;
    socket->write(Data);
}



Client::Client(QString addr)
{
    socket = new QTcpSocket();
    connect(socket, &QTcpSocket::readyRead, this, &Client::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    socket->connectToHost(addr, 2323);
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
    qDebug() << str;
    QStringList list = str.split(' ');
    int command = list[0].toInt();
    int nc      = list[1].toInt();
    switch(command){
    case 1:{
        emit attacked(nc);
        break;
    }
    case -2:{
        emit isReady();
        break;
    }
    case -3:{
        emit responseDamage(nc);
        break;
    }
    case -4:{
        emit responseNonDamage(nc);
        break;
    }
    case -5:{
        emit responseWin();
        break;
    }
    case -6:{
        emit responseKilledObj(nc);
        break;
    }
    }

}
