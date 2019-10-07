#include "hp_tower.h"
#include"scenemanager.h"

#include<QFont>

extern Scenemanager* scenemanager;

HP_tower::HP_tower(QGraphicsItem* parent) : QGraphicsTextItem(parent)
{
    //initial the time to 180s
    hp_tower = 100000;

    //draw the text
    setPlainText(QString("HP: ")+QString::number(hp_tower));    //HP: 100000
    setDefaultTextColor(Qt::red);
    setFont(QFont("main",23));

}

void HP_tower::show_hp_tower(int type)
{
    if(type==1)
    {
        if(scenemanager->game->tower_player->get_tower_HP()>=0)
        {
            setPlainText(QString("HP: ")+QString::number(scenemanager->game->tower_player->get_tower_HP()));
        }
    }
    else if(type==2)
    {
        if(scenemanager->game->tower_enemy->get_tower_HP()>=0)
        {
            setPlainText(QString("HP: ")+QString::number(scenemanager->game->tower_enemy->get_tower_HP()));
        }
    }
}

int HP_tower::get_hp_tower()
{
    return hp_tower;
}
