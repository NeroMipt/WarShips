#ifndef BOARD_H
#define BOARD_H


#include <QList>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <cell.h>

class board : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene * scene;

    void drawPanel(int x, int y, int width, int height, QColor color, double opcaity);


public:
    QList<Cell*> enemyCells;
    QList<Cell*> playerCells;
    board(QGraphicsScene * sc);
    QList<Cell*> setBoard(int x, int y, double scale);
signals:
    void is_Damaged(bool st, int nc);
public slots:
    void rdyBtn_clicked();
    void get_Damage(int nc);

};

#endif // BOARD_H
