#include "board.h"
#include <QtCore>

board::board(QGraphicsScene *sc)
{
    scene = sc;


    this->drawPanel(0, 0, 150, 768, Qt::white, 1);


    QGraphicsTextItem* p1 = new QGraphicsTextItem("Player 1");
    p1->setPos(25, 0);
    scene->addItem(p1);

    playerCells = this->setBoard(200, 250, 1.5);
    enemyCells = this->setBoard(700, 250, 1.5);
}



QList<Cell *> board::setBoard(int x, int y, double scale)
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
    QList<Cell*> sqs;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            Cell * rect = new Cell(x + i * 25 * scale, y + j * 25 *scale, scale, counter, Qt::white);
            counter++;
            sqs.append(rect);
            scene->addItem(rect);

        }
    }
    return sqs;
}

void board::rdyBtn_clicked()
{
    foreach(Cell * i , this->playerCells)
    {
        QList<QGraphicsItem *> list = i->collidingItems() ;
        foreach(QGraphicsItem * t , list)
        {
            Warship * item= dynamic_cast<Warship *>(t);
            if (item)
            {
                item->setPos(item->scenePos() + QPointF(1, 1));
                item->setScale(1.1);
            }
        }
    }
    foreach(Cell * i , this->playerCells)
    {
        QList<QGraphicsItem *> list = i->collidingItems() ;
        foreach(QGraphicsItem * t , list)
        {
            Warship * item= dynamic_cast<Warship *>(t);
            if (item)
            {
                QBrush brush;
                brush.setStyle(Qt::SolidPattern);
                brush.setColor(Qt::blue);
                i->setBrush(brush);
                i->isShip = true;
            }
        }
    }
    foreach(Cell * i , this->playerCells)
    {
        QList<QGraphicsItem *> list = i->collidingItems() ;
        foreach(QGraphicsItem * t , list)
        {
            Warship * item= dynamic_cast<Warship *>(t);
            if (item)
            {
                item->setVisible(false);
                this->ship.append(item);
            }
        }
    }
}

void board::get_Damage(int nc)
{
    foreach(QGraphicsItem * i, this->ship)
    {
        i->setVisible(true);
    }
    bool wounded = false;
    bool isAlive = true;
    QList<QGraphicsItem *> list = playerCells[nc]->collidingItems() ;
    foreach(QGraphicsItem * i , list)
    {
        Warship * item= dynamic_cast<Warship *>(i);
        if (item)
        {
            Healthstate st = item->attacked();
            if(st == Healthstate::Wounded)
            {
                wounded = true;
                QBrush brush;
                brush.setStyle(Qt::SolidPattern);
                brush.setColor(Qt::yellow);
                playerCells[nc]->setBrush(brush);
                emit is_Damaged(false, true, nc);
            }else{
                wounded = true;
                isAlive = false;
                item->setVisible(true);
                item->setScale(1.5);
                item->setPos(item->scenePos() - QPointF(6, 6));
                QBrush brush;
                brush.setStyle(Qt::SolidPattern);
                brush.setColor(Qt::red);
                item->setBrush(brush);
                emit is_Damaged(true, true, nc);
            }
        }
    }
    if(!wounded)
    {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::cyan);
        playerCells[nc]->setBrush(brush);
        emit is_Damaged(false, false, nc);
    }
    if(isAlive)
    {
        foreach(QGraphicsItem * i, this->ship)
        {
            i->setVisible(false);
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

