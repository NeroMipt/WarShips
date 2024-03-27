#ifndef GAMECORE_H
#define GAMECORE_H

#include <QObject>

#include <QList>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <button.h>
#include <board.h>
#include <warship.h>
#include <QMouseEvent>

class GameCore : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene * scene;
    board * obj;
    Boat *b1;
    Boat *b2;
    Boat *b3;
    Boat *b4;
    Destroyer *d1;
    Destroyer *d2;
    Destroyer *d3;
    Battleship *bs1;
    Battleship *bs2;
    Cruiser *c;

    void addShip();
public:
    GameCore(QWidget* parent=NULL);
    void displayMainMenu();
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // GAMECORE_H
