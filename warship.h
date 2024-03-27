#ifndef WARSHIP_H
#define WARSHIP_H
#include <QGraphicsRectItem>
#include <QGraphicsItem>

enum class Healthstate {Healthy, Dead, Wounded};
enum Ship {boat, destroyer, battleship, cruiser};

class Warship : public QGraphicsRectItem
{
private:
    int  size;
    int    hp;
    Ship type;

public:
<<<<<<< HEAD
    Warship(const int s, const Ship sp);
=======
    Warship( const int s, QGraphicsItem *parent=NULL);
>>>>>>> 449fcef (start point)
    Healthstate getState();
    Healthstate attacked();
};

class Boat : public Warship
{
public:
    Boat(const int x, const int y) : Warship(1)
    {
        setRect(x, y, 25, 25);
    }
};

class Destroyer : public Warship
{
public:
    Destroyer(const int x, const int y) : Warship(2)
    {
        setRect(x, y, 25, 50);
    }
};

class Battleship : public Warship
{
public:
    Battleship(const int x, const int y) : Warship(3)
    {
        setRect(x, y, 25, 75);
    }
};

class Cruiser : public Warship
{
public:
    Cruiser(const int x, const int y) : Warship(4)
    {
        setRect(x, y, 25, 100);
    }
};

#endif // WARSHIP_H
