#ifndef CELL_H
#define CELL_H

#include <QObject>
#include <QGraphicsItem>

class Cell : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    int number;
public:
    Cell(const int x, const int y, const double scale, const int n, QColor color, QGraphicsItem *parent = NULL);
};

#endif // CELL_H
