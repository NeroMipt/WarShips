#ifndef FIELD_H
#define FIELD_H

#include <QFrame>
#include <warship.h>

enum Direction {STRAIGHT, SIDE};


class Field
{
private:
<<<<<<< HEAD
    int fd[10][10];
    QList<Warship> army;
    int totalHp = 20;

=======
    int fd[11][11];
>>>>>>> 449fcef (start point)

public:
    Field();
    void addShip(int x, int y, Direction dir, Ship sp);
    void attacked(int x, int y);
    void attack(int x, int y);
    int sumOfField();

};

#endif // FIELD_H
