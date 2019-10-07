#include "start_button.h"

#include"game.h"
#include"start.h"
#include"scenemanager.h"
#include<QGraphicsScene>
#include<QTimer>

extern Scenemanager* scenemanager;

Start_button::Start_button(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem()
{
    //set the icon position
    setPos(490,720);
    //draw the icon
    setPixmap(QPixmap(":/picture/start_button.png"));

    QTimer* timer_button = new QTimer(this);
    connect(timer_button,SIGNAL(timeout()),this,SLOT(move()));
    timer_button->start(1);
}

void Start_button::move()
{
    //move up
    if(pos().y()>385)
    {
        setPos(x(),y()-1);
    }
}
