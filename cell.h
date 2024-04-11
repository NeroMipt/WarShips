#ifndef CELL_H
#define CELL_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>

class Cell : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    QBrush brush;
public:
    int number;
    bool isShip = false;
public:
    Cell(const int x, const int y, const double scale, const int n, QColor color, QGraphicsItem *parent = NULL);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setColor(QColor color);
signals:
    void choosedCell(int ws);
};

#endif // CELL_H
