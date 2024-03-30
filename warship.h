#ifndef WARSHIP_H
#define WARSHIP_H
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QPoint>

enum class Healthstate {Healthy, Dead, Wounded};
enum Ship {boat, destroyer, battleship, cruiser};

class Warship : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    int  size;
    int    hp;
    bool isVertical = true;
    QPointF mouseCoord;
public:
    Warship( const int s, QGraphicsItem *parent=NULL);
    Healthstate getState();
    Healthstate attacked();
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
};

class Boat : public Warship
{
public:
    Boat(const int x, const int y, double scale) : Warship(1)
    {
        setRect(0, 0, 25, 25);
        setPos(x * scale , y * scale);
        setScale(scale);
    }
};

class Destroyer : public Warship
{
public:
    Destroyer(const int x, const int y, double scale) : Warship(2)
    {
        setRect(0, 0, 25, 50);
        setPos(x * scale, y * scale);
        setScale(scale);
    }
};

class Battleship : public Warship
{
public:
    Battleship(const int x, const int y, double scale) : Warship(3)
    {
        setRect(0, 0, 25, 75);
        setPos(x * scale, y * scale);
        setScale(scale);
    }
};

class Cruiser : public Warship
{
public:
    Cruiser(const int x, const int y, double scale) : Warship(4)
    {
        setRect(0, 0, 25, 100);
        setPos(x * scale, y * scale);
        setScale(scale);
    }
};

#endif // WARSHIP_H
