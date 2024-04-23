#include "button.h"

#include <QPainter>


button::button(QString name, QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    setRect(0, 0, 200 ,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    setBrush(brush);

    text = new QGraphicsTextItem(name, this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos, yPos);

    setAcceptHoverEvents(true);
}

void button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
    Q_UNUSED(event);
}

void button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);
    Q_UNUSED(event);
}

void button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    setBrush(brush);
    Q_UNUSED(event);
}
