#ifndef GAMECORE_H
#define GAMECORE_H

#include <QObject>

#include <QList>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <button.h>
#include <board.h>

class GameCore : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene * scene;
    board * obj;
public:
    GameCore(QWidget* parent=NULL);
    void displayMainMenu();
};

#endif // GAMECORE_H
