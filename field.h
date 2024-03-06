#ifndef FIELD_H
#define FIELD_H

#include <QFrame>

enum Direction {STRAIGHT, SIDE};

enum Ship {boat, destroyer, battleship, cruiser};

class Field
{
private:
    int fd[10][10];

public:
    Field();
    void addShip(int x, int y, Direction dir, Ship sp);
    void attacked(int x, int y);

};

#endif // FIELD_H
