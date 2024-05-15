#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDataStream>
#include <QByteArray>

class ClientThread : public QThread
{
    Q_OBJECT

public:
    ClientThread(QTcpSocket *socket1, QTcpSocket *socket2, QObject *parent = nullptr);
    void run();

private:
    QTcpSocket *socket1;
    QTcpSocket *socket2;
    void onReadyRead();
    QByteArray Data;
};

#endif // CLIENTTHREAD_H
