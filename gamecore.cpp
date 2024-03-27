#include "gamecore.h"

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
    //obj = new board(scene);

    //this->addShip();
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

    button * playBtn = new button(QString("Play"));
    int bxPos =this->width()/2 - playBtn->boundingRect().width()/2;
    int byPos = 275;
    playBtn->setPos(bxPos, byPos);
    //connect(playBtn, SIGNAL(clicked()), this, SLOT(setBoard()));
    scene->addItem(playBtn);

    button * quitBtn = new button(QString("Quit"));
    int bqxPos =this->width()/2 - quitBtn->boundingRect().width()/2;
    int bqyPos = 475;
    quitBtn->setPos(bqxPos, bqyPos);
    connect(quitBtn, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitBtn);
}


void GameCore::addShip()
{
    b1 = new Boat(10, 40);
    scene->addItem(b1);
    b2 = new Boat(40, 40);
    scene->addItem(b2);
    b3 = new Boat(10, 70);
    scene->addItem(b3);
    b4 = new Boat(40, 70);
    scene->addItem(b4);
    d1 = new Destroyer(70, 40);
    scene->addItem(d1);
    d2 = new Destroyer(100, 40);
    scene->addItem(d2);
    d3 = new Destroyer(70, 100);
    scene->addItem(d3);
    bs1 = new Battleship(10, 100);
    scene->addItem(bs1);
    bs2 = new Battleship(40, 100);
    scene->addItem(bs2);
    c = new Cruiser(100, 100);
    scene->addItem(c);
}

void GameCore::mouseMoveEvent(QMouseEvent *event)
{

}
