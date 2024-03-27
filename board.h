#ifndef BOARD_H
#define BOARD_H


#include <QList>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <warship.h>

class board : public QGraphicsView
{
    Q_OBJECT
private:
    QList<QGraphicsRectItem*> sqs;
    QGraphicsScene * scene;
    Boat *b;
public:
    board(QGraphicsScene * sc);
    void setBoard(int x, int y);

};

#endif // BOARD_H
