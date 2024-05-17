#ifndef SERVER_H
#define SERVER_H

#define PORT 2323

#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QThread>
#include <QDataStream>
#include "include/incsv/clientthread.h"

class ClientThread;

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(QObject *parent = nullptr);

private slots:
    void onNewConnection();
    void onDisconnected();

private:
    QVector<QTcpSocket*> clients;
    QVector<QThread*> threads;
};

#endif // SERVER_H
