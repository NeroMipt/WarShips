#include "board.h"
#include <QtCore>
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
    int counter = 0;
    Cell *tl = new Cell(x, y, 1.5, -1, Qt::gray);
    Cell *tr = new Cell(x + 275*scale, y, 1.5, -1, Qt::gray);
    scene->addItem(tl);
    scene->addItem(tr);
    int num = 49;
    y+=25 * scale;
    for(int i = 0; i <= 10; i++)
    {
        char letter;
        letter = (char)num;
        QGraphicsTextItem* p1 = new QGraphicsTextItem(QString(QChar::fromLatin1(letter)));
        num++;
        p1->setPos(x, y + i * 25 * scale);
        p1->setScale(scale);
        Cell *bdr = new Cell(x + 275 * scale, y + i * 25 * scale - 1, 1.5, -1, Qt::gray);
        scene->addItem(p1);
        scene->addItem(bdr);
    }
    num = 65;
    y-= 25 * scale;
    Cell *bl = new Cell(x, y + 275 * scale, 1.5, -1, Qt::gray);
    scene->addItem(bl);
    x+=25 * scale;
    for(int i = 0; i < 10; i++)
    {
        char letter;
        letter = (char)num;
        QGraphicsTextItem* p1 = new QGraphicsTextItem(QString(QChar::fromLatin1(letter)));
        num++;
        p1->setPos(x + i * 25 * scale + 5, y);
        p1->setScale(scale);
        Cell *bdb = new Cell(x + i * 25 * scale, y + 275 * scale, 1.5, -1, Qt::gray);
        scene->addItem(p1);
        scene->addItem(bdb);
    }
    y += 25 * scale;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            counter++;
            Cell * rect = new Cell(x + i * 25 * scale, y + j * 25 *scale, scale, counter, Qt::white);
            sqs.append(rect);

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

