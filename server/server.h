#ifndef SERVER_H
#define SERVER_H

#define PORT 2323

#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include <QThread>
#include <QQueue>

class Server;

class ClientThread : public QThread
{
    Q_OBJECT

public:
    explicit ClientThread(QTcpSocket *socket, QPair<QTcpSocket*, QTcpSocket*> *sockets, Server *server, QObject *parent = nullptr);

protected:
    void run() override;

signals:
    void finished();

private:
    QTcpSocket *socket;
    QPair<QTcpSocket*, QTcpSocket*> *sockets;
    Server *server;
};

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server();
    ~Server();

    void SendToClient1(const QString &message);
    void SendToClient2(const QString &message);

private:
    QPair <QTcpSocket*, QTcpSocket*> Sockets;
    QList<ClientThread*> clientThreads;
    QQueue<QTcpSocket*> waitingClients;

public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();

};

#endif // SERVER_H
