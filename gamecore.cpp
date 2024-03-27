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

    obj = new board(scene);
    obj->setBoard(100, 100);
    obj->setBoard(500, 500);
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
