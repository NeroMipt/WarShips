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
#include <QMessageBox>

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
