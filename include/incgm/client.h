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
    Client(QString addr);
    void SendToServer(int num, int nc);
public slots:
    void slotReadyRead();
signals:
    void attacked(int nc);
    void responseDamage(int nc);
    void responseNonDamage(int nc);
    void responseKilledObj(int nc);
    void responseWin();
    void isReady();
};

#endif // CLIENT_H
