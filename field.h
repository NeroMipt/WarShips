#ifndef FIELD_H
#define FIELD_H

#include <QFrame>
#include <warship.h>

enum Direction {STRAIGHT, SIDE};


class Field
{
private:
    int fd[10][10];
    QList<Warship> army;


public:
    Field();
    void addShip(int x, int y, Direction dir, Ship sp);
    void attacked(int x, int y);

};

#endif // FIELD_H
