#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDataStream>

class Client : public QObject
{
    Q_OBJECT
private:
    QTcpSocket *socket;
    QByteArray Data;
    void SendToServer(QString str);
    void connection(QString address);
public:
    Client();
public slots:
    void slotReadyRead();
};

#endif // CLIENT_H
