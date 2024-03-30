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
        setRect(x * scale, y * scale, 25*scale, 25*scale);
    }
};

class Destroyer : public Warship
{
public:
    Destroyer(const int x, const int y, double scale) : Warship(2)
    {
        setRect(x * scale, y * scale, 25*scale, 50*scale);
    }
};

class Battleship : public Warship
{
public:
    Battleship(const int x, const int y, double scale) : Warship(3)
    {
        setRect(x*scale, y * scale, 25*scale, 75*scale);
    }
};

class Cruiser : public Warship
{
public:
    Cruiser(const int x, const int y, double scale) : Warship(4)
    {
        setRect(x*scale, y*scale, 25*scale, 100*scale);
    }
};

#endif // WARSHIP_H
