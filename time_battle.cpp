#include "time_battle.h"
#include"scenemanager.h"

#include<QFont>

extern Scenemanager* scenemanager;

Time_battle::Time_battle(QGraphicsItem* parent) : QGraphicsTextItem(parent)
{
    //initial the time to 180s
    time = 180;

    //draw the text
    setPlainText(QString("Time: ")+QString::number(time)+QString(" s"));    //Time: 180 s
    setDefaultTextColor(Qt::white);
    setFont(QFont("main",27));
}

void Time_battle::time_decrease()
{
    if(time>0)
    {
        time--;
        setPlainText(QString("Time: ")+QString::number(time)+QString(" s"));
    }
    else
    {
        scenemanager->changescene(2);
        return;
    }
}

int Time_battle::get_time_battle()
{
    return time;
}
