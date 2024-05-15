#include "board.h"
#include <QtCore>

board::board(QGraphicsScene *sc)
{
    scene = sc;


    this->drawPanel(0, 0, 175, 768, Qt::white, 1);


    QGraphicsTextItem* p1 = new QGraphicsTextItem("Player 1");
    p1->setPos(25, 0);
    scene->addItem(p1);

    QGraphicsTextItem* tnwd = new QGraphicsTextItem("- мимо");
    QGraphicsTextItem* twd = new QGraphicsTextItem("- ранен");
    QGraphicsTextItem* tkd = new QGraphicsTextItem("- убит");
    tnwd->setScale(1.1);
    twd->setScale(1.1);
    tkd->setScale(1.1);
    tnwd->setPos(40, 600);
    twd->setPos(40, 650);
    tkd->setPos(40, 700);
    scene->addItem(tnwd);
    scene->addItem(twd);
    scene->addItem(tkd);
    Cell *nwd = new Cell(10, 600, 1.1, -1, Qt::cyan, true);
    Cell *wd = new Cell(10, 650, 1.1, -1, Qt::yellow, true);
    Cell *kd = new Cell(10, 700, 1.1, -1, Qt::red, true);
    scene->addItem(nwd);
    scene->addItem(wd);
    scene->addItem(kd);

    playerCells = this->setBoard(200, 175, 1.5, false);
    enemyCells = this->setBoard(700, 175, 1.5, true);

}



QList<Cell *> board::setBoard(int x, int y, double scale, bool isEn)
{
    int counter = 0;
    Cell *tl = new Cell(x, y, 1.5, -1, Qt::gray, true);
    Cell *tr = new Cell(x + 275*scale, y, 1.5, -1, Qt::gray, true);
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
        Cell *bdr = new Cell(x + 275 * scale, y + i * 25 * scale - 1, 1.5, -1, Qt::gray, true);
        scene->addItem(p1);
        scene->addItem(bdr);
    }
    num = 65;
    y-= 25 * scale;
    Cell *bl = new Cell(x, y + 275 * scale, 1.5, -1, Qt::gray, true);
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
        Cell *bdb = new Cell(x + i * 25 * scale, y + 275 * scale, 1.5, -1, Qt::gray, true);
        scene->addItem(p1);
        scene->addItem(bdb);
    }
    y += 25 * scale;
    QList<Cell*> sqs;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            Cell * rect = new Cell(x + i * 25 * scale, y + j * 25 *scale, scale, counter, Qt::white, isEn);
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
                if(item->is_Vertical())
                {
                    item->setPos(item->scenePos() + QPointF(1, 1));
                    item->setScale(1.1);
                }else{
                    item->setPos(item->scenePos() + QPointF(1, -1));
                    item->setScale(1.1);
                }
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
                i->set_isShip(true);
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
                item->setAcceptDrops(false);
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
    QList<QGraphicsItem *> list = playerCells[nc]->collidingItems() ;
    foreach(QGraphicsItem * i , list)
    {
        Warship * item= dynamic_cast<Warship *>(i);
        if (item && item->getHealth())
        {
            Healthstate st = item->attacked();
            if(st == Healthstate::Wounded)
            {
                wounded = true;
                playerCells[nc]->setColor(Qt::yellow);
                emit is_Damaged(false, true, nc);
            }else{
                wounded = true;
                ship.removeAt(ship.indexOf(item));
                item->setVisible(true);
                QList<QGraphicsItem *> list = item->collidingItems() ;
                if(item->is_Vertical() == false)
                    item->setPos(list.back()->scenePos() + QPointF(0, 25 * 1.5));
                else
                    item->setPos(list.back()->scenePos());
                item->setScale(1.5);
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
        playerCells[nc]->setColor(Qt::cyan);
        emit is_Damaged(false, false, nc);
    }

    foreach(QGraphicsItem * i, this->ship)
    {
        i->setVisible(false);
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

