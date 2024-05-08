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
    bool isCollided = false;
    bool isPlaced = false;
    QPointF mouseCoord;
public:
    QPointF coords;
    double originalScale;
    Warship( const int s, QGraphicsItem *parent=NULL);
    Healthstate attacked();
    int getHealth();
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    bool is_Vertical();
    bool is_Placed();
};

class Boat : public Warship
{
public:
    Boat(const int x, const int y, double scale) : Warship(1)
    {
        setRect(0, 0, 25, 25);
        setPos(x * scale , y * scale);
        setScale(scale);
        coords = QPointF(x, y);
        originalScale = scale;
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
        coords = QPointF(x, y);
        originalScale = scale;
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
        coords = QPointF(x, y);
        originalScale = scale;
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
        coords = QPointF(x, y);
        originalScale = scale;
    }
};

#endif // WARSHIP_H
