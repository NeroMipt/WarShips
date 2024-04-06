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
#include <client.h>

class GameCore : public QGraphicsView
{
    Q_OBJECT
private:
    int totalHP = 20;
    Client *cl;
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
private slots:
    void exec();
    void isReady();
    void isDamaged(bool tof, int nc);
    void attacking(int nc);
    void damaged(int nc);
    void nonDamaged(int nc);
};

#endif // GAMECORE_H
