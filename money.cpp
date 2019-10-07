#include "money.h"

#include<QFont>
#include"game.h"

#include"scenemanager.h"

extern Game* game;
extern Scenemanager* scenemanager;

Money::Money(QGraphicsItem* parent) : QGraphicsTextItem(parent)
{
    //initial the money to 0
    money = 0;

    //draw the text
    setPlainText(QString("Money: ")+QString::number(money)+QString(" $"));    //Money: 0 $
    setDefaultTextColor(Qt::yellow);
    setPos(x()+1050,y());
    setFont(QFont("main",27));
}

void Money::money_increase()
{
    if(money<10)
    {
        if(scenemanager->game->time_battle->get_time_battle()<=60)
        {
            money=money+2;
            if(money>10)
                money=10;
            setPlainText(QString("Money: ")+QString::number(money)+QString(" $"));   //Money: 2 $
        }
        else
        {
            money++;
            if(money>10)
                money=10;
            setPlainText(QString("Money: ")+QString::number(money)+QString(" $"));   //Money: 1 $
        }
    }
    if(scenemanager->game->time_battle->get_time_battle()<=30)
    {
        money+=2;
        setPlainText(QString("Money: ")+QString::number(money)+QString(" $"));   //Money: 1 $
    }
}

void Money::money_decrease(int decrease_num)
{
    money = money -decrease_num;
    setPlainText(QString("Money: ")+QString::number(money)+QString(" $"));
}

int Money::get_money()
{
    return money;
}
