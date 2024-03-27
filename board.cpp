#include "board.h"

board::board(QGraphicsScene *sc)
{
    scene = sc;
    b = new Boat(10, 10);
    scene->addItem(b);
}



void board::setBoard(int x, int y)
{
    //scene->clear();
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            QGraphicsRectItem * rect = new QGraphicsRectItem();

            rect->setRect(x + i * 25,y + j * 25, 25, 25);

            scene->addItem(rect);

        }
    }
}
