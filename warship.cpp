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
        int counter = 0;
        foreach(QGraphicsItem * j , list)
        {
            Cell * itemCell = dynamic_cast<Cell *>(j);
            if(itemCell)
            {
                if(!itemCell->isOpponent())
                {
                    counter++;
                }
            }
        }
        if(counter == size)
        {
            setScale(1.7);

            if(isVertical)
                setPos(list.back()->scenePos() - QPointF(5, 5));
            else
                setPos(list.back()->scenePos() + QPointF(0, 29.7 * originalScale));

            isCollided = false;
            QList<QGraphicsItem *> listAfter = collidingItems() ;

            foreach(QGraphicsItem * i , listAfter)
            {
                Warship * item= dynamic_cast<Warship *>(i);
                if (item)
                {
                    setScale(originalScale);
                    setPos(coords * originalScale);
                    isCollided = true;
                    isPlaced = false;
                }

            }
        }else
        {
            setScale(originalScale);
            setPos(coords * originalScale);
            isCollided = true;
            isPlaced = false;
        }
        if(isCollided == false)
        {
            if(isVertical == false)
                setPos(list.back()->scenePos() + QPointF(0, 29.7 * originalScale));
            else
                setPos(list.back()->scenePos());
            setScale(1.5);
            isPlaced = true;
        }
    }else
    {
        setPos(coords * originalScale);
    }
    Q_UNUSED(event);
}

void Warship::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    mouseCoord = this->pos() - mapToScene(event->pos());
    if(isVertical == true)
    {
        setRotation(-90);
        isVertical = false;
    }
    else{
        setRotation(0);

        isVertical = true;
    }
}


bool Warship::is_Vertical()
{
    return isVertical;
}

bool Warship::is_Placed()
{
    return isPlaced;
}
