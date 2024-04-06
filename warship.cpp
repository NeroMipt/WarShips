#include "warship.h"
#include <QPainter>
#include <QtCore>
#include <QCursor>
#include <QList>
#include <cell.h>

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
    setScale(1.1);
    mouseCoord = this->pos() - mapToScene(event->pos());
    this->setCursor(QCursor(Qt::ClosedHandCursor));
}

void Warship::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    QList<QGraphicsItem *> list = collidingItems() ;


    if(!list.isEmpty())
    {
        setScale(1.7);
        setPos(list.back()->scenePos() - QPointF(5, 5));
        isCollided = false;
        QList<QGraphicsItem *> listAfter = collidingItems() ;

        foreach(QGraphicsItem * i , listAfter)
        {
            Warship * item= dynamic_cast<Warship *>(i);
            //Cell * itemCell = dynamic_cast<Cell *>(i);
            if (item)
            {
                setScale(originalScale);
                setPos(coords * originalScale);
                isCollided = true;
            }
            /*if(!(itemCell->number >= 0))
            {
                setScale(originalScale);
                setPos(coords * originalScale);
                isCollided = true;
            }*/

        }
        if(isCollided == false)
        {
            if(isVertical == false)
                setPos(list.back()->scenePos() + QPointF(0, 29.6 * originalScale));
            else
                setPos(list.back()->scenePos());
            setScale(1.5);
        }
    }else
        setPos(coords * originalScale);
    Q_UNUSED(event);
}

void Warship::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    mouseCoord = this->pos() - mapToScene(event->pos());
    if(isVertical == true)
    {
        setTransformOriginPoint(this->scenePos());
        setRotation(-90);
        setTransformOriginPoint(0, 0);
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

