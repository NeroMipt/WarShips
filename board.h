#ifndef BOARD_H
#define BOARD_H


#include <QList>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

class board : public QGraphicsView
{
    Q_OBJECT
private:
    QList<QGraphicsRectItem*> sqs;
    QGraphicsScene * scene;

    void drawPanel(int x, int y, int width, int height, QColor color, double opcaity);


public:
    board(QGraphicsScene * sc);
    void setBoard(int x, int y, double scale);

};

#endif // BOARD_H
