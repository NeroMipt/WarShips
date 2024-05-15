#include "clientthread.h"

ClientThread::ClientThread(QTcpSocket *socket1, QTcpSocket *socket2, QObject *parent) :
    QThread(parent), socket1(socket1), socket2(socket2)
// конструктор для ClientThread, который будет обрабатывать socket1 и socket2
{
    connect(socket1, &QTcpSocket::readyRead, this, &ClientThread::onReadyRead);
    connect(socket2, &QTcpSocket::readyRead, this, &ClientThread::onReadyRead);
}

void ClientThread::run()
{
    exec();
}

void ClientThread::onReadyRead()
{
    Data.clear();
    QTcpSocket* senderSocket = (QTcpSocket*)sender();
    QDataStream in(senderSocket);
    in.setVersion(QDataStream::Qt_5_9);
    QString str;
    in >> str;
    qDebug() << "recieved message: " << str;

    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out << str;

    QTcpSocket *receiverSocket = (senderSocket == socket1) ? socket2 : socket1;
    qDebug() << "sender socket:" << senderSocket << "\t reciever socket" << receiverSocket << "\n";
    receiverSocket->write(Data);
}
