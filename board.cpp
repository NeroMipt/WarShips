#include "board.h"

board::board(QGraphicsScene *sc)
{
    scene = sc;


    this->drawPanel(0, 0, 150, 768, Qt::white, 1);



    QGraphicsTextItem* p1 = new QGraphicsTextItem("Player 1");
    p1->setPos(25, 0);
    scene->addItem(p1);

    this->setBoard(200, 250, 1.5);
    this->setBoard(700, 250, 1.5);
}



void board::setBoard(int x, int y, double scale)
{

    //scene->clear();
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            QGraphicsRectItem * rect = new QGraphicsRectItem();

            rect->setRect(0, 0, 25*scale, 25*scale);
            rect->setPos(x + i * 25*scale,y + j * 25*scale);

            scene->addItem(rect);

        }
    }
}

void board::drawPanel(int x, int y, int width, int height, QColor color, double opcaity)
{
    QGraphicsRectItem* panel = new QGraphicsRectItem(x, y, width, height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opcaity);
    scene->addItem(panel);
}

