#include "warship.h"
#include <QPainter>

<<<<<<< HEAD
Warship::Warship( const int s , const Ship sp )
{
    size = s;
    hp   = s;
    type = sp;
=======
Warship::Warship(const int s , QGraphicsItem *parent)
{
    size = s;
    hp   = s;

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

>>>>>>> 449fcef (start point)
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

Healthstate Warship::getState()
{
    if(hp == size) return Healthstate::Healthy;
    if(hp == 0) return Healthstate::Dead;
    else return Healthstate::Wounded;
}

/*void Warship::rotate()
{
    setRotation(90);
}*/
