#include "gamecore.h"
#include <cell.h>

GameCore::GameCore(QWidget *parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024, 768);
    scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, 1024, 768);
    QGraphicsView * view = new QGraphicsView(scene);
    view->show();
    this->displayMainMenu();
    Q_UNUSED(parent);
}

void GameCore::displayMainMenu()
{
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("War Ships"));
    QFont titleFont("sdsds", 50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos, tyPos);
    scene->addItem(titleText);

    button * playBtn = new button(QString("Connect"));
    int bxPos =this->width()/2 - playBtn->boundingRect().width()/2;
    int byPos = 275;
    playBtn->setPos(bxPos, byPos);
    connect(playBtn, SIGNAL(clicked()), this, SLOT(exec()));
    scene->addItem(playBtn);

    button * quitBtn = new button(QString("Quit"));
    int bqxPos =this->width()/2 - quitBtn->boundingRect().width()/2;
    int bqyPos = 475;
    quitBtn->setPos(bqxPos, bqyPos);
    connect(quitBtn, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitBtn);
}

void GameCore::exec()
{
    cl = new Client();
    scene->clear();
    obj = new board(scene);
    button * rdyBtn = new  button(QString("Ready"));
    rdyBtn->setPos(500, 100);
    rdyBtn->setScale(1);
    connect(rdyBtn, SIGNAL(clicked()), this, SLOT(isReady()));
    connect(rdyBtn, SIGNAL(clicked()), obj, SLOT(rdyBtn_clicked()));
    connect(cl, SIGNAL(attacked(int)), obj, SLOT(get_Damage(int)));
    connect(cl, SIGNAL(responseDamage(int)), this, SLOT(damaged(int)));
    connect(cl, SIGNAL(responseNonDamage(int)), this, SLOT(nonDamaged(int)));
    connect(obj, SIGNAL(is_Damaged(bool,int)), this, SLOT(isDamaged(bool,int)));
    scene->addItem(rdyBtn);
    foreach(Cell * i , obj->enemyCells)
    {
        connect(i, SIGNAL(choosedCell(int)), this, SLOT(attacking(int)));
    }
    this->addShip();
}

void GameCore::isReady()
{
    cl->SendToServer(-2, -1);
}

void GameCore::isDamaged(bool tof, int nc)
{
    if(tof)
    {
        totalHP--;
        if(totalHP == 0)
            cl->SendToServer(-5, nc);
        cl->SendToServer(-3, nc);
    }else cl->SendToServer(-4, nc);
}

void GameCore::attacking(int nc)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::yellow);
    obj->enemyCells[nc]->setBrush(brush);
    cl->SendToServer(1, nc);
}

void GameCore::damaged(int nc)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    obj->enemyCells[nc]->setBrush(brush);
}

void GameCore::nonDamaged(int nc)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    obj->enemyCells[nc]->setBrush(brush);
}


void GameCore::addShip()
{
    b1 = new Boat(10, 40, 1.25);
    scene->addItem(b1);
    b2 = new Boat(40, 40, 1.25);
    scene->addItem(b2);
    b3 = new Boat(10, 70, 1.25);
    scene->addItem(b3);
    b4 = new Boat(40, 70, 1.25);
    scene->addItem(b4);
    d1 = new Destroyer(70, 40, 1.25);
    scene->addItem(d1);
    d2 = new Destroyer(100, 40, 1.25);
    scene->addItem(d2);
    d3 = new Destroyer(70, 100, 1.25);
    scene->addItem(d3);
    bs1 = new Battleship(10, 100, 1.25);
    scene->addItem(bs1);
    bs2 = new Battleship(40, 100, 1.25);
    scene->addItem(bs2);
    c = new Cruiser(100, 100, 1.25);
    scene->addItem(c);
}
