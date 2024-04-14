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
    int number;
    bool isShip = false;
    bool enemy;
public:
    Cell(const int x, const int y, const double scale, const int n, QColor color, const bool enorn, QGraphicsItem *parent = NULL);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setColor(QColor color);
    bool isOpponent();
    bool is_Ship();
    void set_isShip(bool tf);
    int get_Num();
signals:
    void choosedCell(int ws);
};

#endif // CELL_H
