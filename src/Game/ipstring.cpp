#include "include/incgm/ipstring.h"
#include <QDebug>

ipstring::ipstring(int x, int y)
{
    setPlainText("Enter IP address");
    setTextInteractionFlags(Qt::TextEditorInteraction);
    setPos(x - boundingRect().width()/2, y);
}

void ipstring::focusOutEvent(QFocusEvent *event)
{
    QString ipRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";
    int pos = 0;
    QRegExp ipRegex ("^" + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange + "$");
    QRegExpValidator *ipValidator = new QRegExpValidator(ipRegex, this);
    ip_address = toPlainText();



    if(ip_address.isEmpty() || !(ipValidator->validate(ip_address, pos) == QValidator::Acceptable))
    {
        ip_address = QString("");
        setPlainText("Enter IP address");
    }
    Q_UNUSED(event);
}

QString ipstring::getText()
{
    return ip_address;
}
