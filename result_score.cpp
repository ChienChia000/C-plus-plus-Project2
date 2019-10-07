#include "result_score.h"

#include<QFont>

#include"scenemanager.h"

extern Scenemanager* scenemanager;

Result_score::Result_score(QGraphicsItem* parent, int type) : QGraphicsTextItem(parent)
{
    if(type == 1)
    {
        //draw the Score
        setPlainText(QString("Score: ")+QString::number(scenemanager->battle_score)+QString(" X10"));
        setDefaultTextColor(Qt::white);
        setPos(x()+155,y()+40);
        setFont(QFont("main",45));
    }
    else if(type == 2)
    {
        //draw the tower HP
        setPlainText(QString("Tower HP: ")+QString::number(scenemanager->tower_left_HP)+QString(" X2"));
        setDefaultTextColor(Qt::white);
        setPos(x()+155,y()+100);
        setFont(QFont("main",45));
    }
    else if(type == 3)
    {
        //draw the time
        setPlainText(QString("Time: ")+QString::number(scenemanager->battle_time)+QString(" X7"));
        setDefaultTextColor(Qt::white);
        setPos(x()+155,y()+160);
        setFont(QFont("main",45));
    }
    else if(type == 4)
    {
        int total = 0;
        total = total+(scenemanager->battle_score)*10+(scenemanager->tower_left_HP)*2+(scenemanager->battle_time)*7;
        //draw the total score
        setPlainText(QString("Total: ")+QString::number(total));
        setDefaultTextColor(Qt::yellow);
        setPos(x()+155,y()+270);
        setFont(QFont("main",45));
    }
    else if(type == 5)  //tie
    {
        setPlainText(QString("Tie"));
        setDefaultTextColor(Qt::yellow);
        setPos(x()+390,y()+150);
        setFont(QFont("main",90));
    }
    else if(type == 6)  //lose
    {
        setPlainText(QString("You Lose"));
        setDefaultTextColor(Qt::yellow);
        setPos(x()+220,y()+140);
        setFont(QFont("main",90));
    }
}
