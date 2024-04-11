#include "cell.h"


Cell::Cell(const int x, const int y, const double scale, int n, QColor color, QGraphicsItem *parent)
{
    number = n;
    setRect(0, 0, 25, 25);
    setPos(x, y);
    setScale(scale);
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    setBrush(brush);
    Q_UNUSED(parent);
}

void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit choosedCell(number);
    Q_UNUSED(event);
}

void Cell::setColor(QColor color)
{
    brush.setColor(color);
    setBrush(brush);
}
