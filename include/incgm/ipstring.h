#ifndef IPSTRING_H
#define IPSTRING_H

#include <QRegExpValidator>
#include <QGraphicsTextItem>


class ipstring : public QGraphicsTextItem
{
    Q_OBJECT
private:
    QString ip_address = QString("");
public:
    ipstring(int x, int y);
    void focusOutEvent(QFocusEvent *event);
    QString getText();
};

#endif // IPSTRING_H
