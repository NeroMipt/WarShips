#ifndef SERVER_H
#define SERVER_H

#define PORT 2323

#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>

class Server : public QTcpServer
{
private:
    Q_OBJECT

public:
    Server();
    QTcpSocket *socket;

private:
    QPair <QTcpSocket*, QTcpSocket*> Sockets;
    QByteArray Data;
    void SendToClient1(QString str);
    void SendToClient2(QString str);

public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();

};

#endif // SERVER_H
