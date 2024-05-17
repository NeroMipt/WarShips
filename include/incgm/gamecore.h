#ifndef GAMECORE_H
#define GAMECORE_H

#include <QObject>

#include <QList>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "include/incgm/button.h"
#include "include/incgm/board.h"
#include "include/incgm/warship.h"
#include <QMouseEvent>
#include "include/incgm/client.h"
#include <QMessageBox>
#include <QGraphicsTextItem>
#include "include/incgm/ipstring.h"

class GameCore : public QGraphicsView
{
    Q_OBJECT
private:
    int totalHP = 20;
    Client *cl;
    QGraphicsScene * scene;
    board * obj;
    button * rdyBtn;
    QGraphicsView * view;
    QList<Warship*> ship;
    ipstring *ip_add;
    void addShip();
    void toggle_Interactions(bool is_On);
public:
    GameCore(QWidget* parent=NULL);
    void displayMainMenu();
private slots:
    void exec();
    void isReady();
    void isDamaged(bool isKilled, bool tof, int nc);
    void attacking(int nc);
    void damaged(int nc);
    void nonDamaged(int nc);
    void killedSh(int nc);
    void opIsRdy();
};

#endif // GAMECORE_H
