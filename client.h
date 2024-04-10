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
public:
    Client();
    void SendToServer(int num, int nc);
public slots:
    void slotReadyRead();
signals:
    void attacked(int nc);
    void responseDamage(int nc);
    void responseNonDamage(int nc);
    void responseWin();
};

#endif // CLIENT_H
