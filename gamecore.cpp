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
    rdyBtn = new  button(QString("Ready"));
    rdyBtn->setPos(500, 100);
    rdyBtn->setScale(1);
    connect(rdyBtn, SIGNAL(clicked()), this, SLOT(isReady()));
    connect(rdyBtn, SIGNAL(clicked()), obj, SLOT(rdyBtn_clicked()));
    connect(cl, SIGNAL(attacked(int)), obj, SLOT(get_Damage(int)));
    connect(cl, SIGNAL(responseDamage(int)), this, SLOT(damaged(int)));
    connect(cl, SIGNAL(responseNonDamage(int)), this, SLOT(nonDamaged(int)));
    connect(cl, SIGNAL(responseKilledObj(int)), this, SLOT(killedSh(int)));
    connect(obj, SIGNAL(is_Damaged(bool,bool,int)), this, SLOT(isDamaged(bool,bool,int)));
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
    scene->removeItem(rdyBtn);
}

void GameCore::isDamaged(bool isKilled, bool tof, int nc)
{
    if(tof)
    {
        totalHP--;
        if(totalHP == 0)
            cl->SendToServer(-5, nc);
        if(isKilled)
            cl->SendToServer(-6, nc);
        else
            cl->SendToServer(-3, nc);
    }else cl->SendToServer(-4, nc);
}

void GameCore::attacking(int nc)
{
    obj->enemyCells[nc]->setColor(Qt::yellow);
    cl->SendToServer(1, nc);
}

void GameCore::damaged(int nc)
{
    obj->enemyCells[nc]->setColor(Qt::yellow);
    obj->enemyCells[nc]->set_isShip(true);
}

void GameCore::nonDamaged(int nc)
{
    obj->enemyCells[nc]->setColor(Qt::cyan);
}

void GameCore::killedSh(int nc)
{
    qDebug() << nc;
    obj->enemyCells[nc]->setColor(Qt::red);
    if(nc >= 1)
    {
        if(obj->enemyCells[nc-1]->is_Ship()){
            int i = nc - 1;
            while(obj->enemyCells[i]->is_Ship())
            {
                obj->enemyCells[i]->setColor(Qt::red);
                i--;
            }
        }
    }
    if(nc < 99)
    {
        if(obj->enemyCells[nc+1]->is_Ship())
        {
            int i = nc + 1;
            while(obj->enemyCells[i]->is_Ship())
            {
                obj->enemyCells[i]->setColor(Qt::red);
                i++;
            }
        }
    }
    if(nc <= 89)
    {
        if(obj->enemyCells[nc+10]->is_Ship())
        {
            int i = nc + 10;
            while(obj->enemyCells[i]->is_Ship())
            {
                obj->enemyCells[i]->setColor(Qt::red);
                i+=10;
            }
        }
    }
    if(nc >= 10)
    {
        if(obj->enemyCells[nc-10]->is_Ship())
        {
            int i = nc - 10;
            while(obj->enemyCells[i]->is_Ship())
            {
                obj->enemyCells[i]->setColor(Qt::red);
                i-=10;
            }
        }
    }
}


void GameCore::addShip()
{
    Boat *b1 = new Boat(10, 40, 1.25);
    scene->addItem(b1);
    Boat *b2 = new Boat(40, 40, 1.25);
    scene->addItem(b2);
    Boat *b3 = new Boat(10, 70, 1.25);
    scene->addItem(b3);
    Boat *b4 = new Boat(40, 70, 1.25);
    scene->addItem(b4);
    Destroyer *d1 = new Destroyer(70, 40, 1.25);
    scene->addItem(d1);
    Destroyer *d2 = new Destroyer(100, 40, 1.25);
    scene->addItem(d2);
    Destroyer *d3 = new Destroyer(70, 100, 1.25);
    scene->addItem(d3);
    Battleship *bs1 = new Battleship(10, 100, 1.25);
    scene->addItem(bs1);
    Battleship *bs2 = new Battleship(40, 100, 1.25);
    scene->addItem(bs2);
    Cruiser *c = new Cruiser(100, 100, 1.25);
    scene->addItem(c);

}
