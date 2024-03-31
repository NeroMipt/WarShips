#include "warship.h"
#include <QPainter>
#include <QtCore>
#include <QCursor>
#include <QList>

Warship::Warship(const int s , QGraphicsItem *parent)
{
    size = s;
    hp   = s;

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);
    Q_UNUSED(parent);
}

Healthstate Warship::attacked()
{
    if(hp > 1){
        hp--;
        return Healthstate::Wounded;
    }
    else{
        hp--;
        return Healthstate::Dead;
    }
}

void Warship::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()) + mouseCoord);
}

void Warship::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setScale(1.25);
    mouseCoord = this->pos() - mapToScene(event->pos());
    this->setCursor(QCursor(Qt::ClosedHandCursor));
}

void Warship::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    QList<QGraphicsItem *> list = collidingItems() ;

    foreach(QGraphicsItem * i , list)
    {
        setPos(i->scenePos());
        //qDebug() << i->pos() << "\n";
    }
    setScale(1.6);
    QList<QGraphicsItem *> listAfter = collidingItems() ;
    qDebug() << listAfter.size();
    if(listAfter.size() > 3 * size + 6)
    {
      qDebug() << coords;
      setScale(originalScale);
      setPos(coords * originalScale);
    }else{
        setScale(1.5);
    }
    Q_UNUSED(event);
}

void Warship::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    mouseCoord = this->pos() - mapToScene(event->pos());
    if(isVertical == true)
    {
        setRotation(90);
        this->setPos(mapToScene(event->pos()) + mouseCoord);
        isVertical = false;
    }
    else{
        setRotation(0);
        this->setPos(mapToScene(event->pos()) + mouseCoord);
        isVertical = true;
    }
}

Healthstate Warship::getState()
{
    if(hp == size) return Healthstate::Healthy;
    if(hp == 0) return Healthstate::Dead;
    else return Healthstate::Wounded;
}

