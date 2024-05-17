#ifndef BOARD_H
#define BOARD_H


#include <QList>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "include/incgm/cell.h"
#include "include/incgm/warship.h"

class board : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene * scene;

    void drawPanel(int x, int y, int width, int height, QColor color, double opcaity);


public:
    QList<Cell*> enemyCells;
    QList<Cell*> playerCells;
    QList<QGraphicsItem*> ship;
    board(QGraphicsScene * sc);
    QList<Cell*> setBoard(int x, int y, double scale, bool isEn);
    void rdyBtn_clicked();
signals:
    void is_Damaged(bool isKilled, bool st, int nc);
public slots:
    void get_Damage(int nc);

};

#endif // BOARD_H
