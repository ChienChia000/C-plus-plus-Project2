#include "tower_player.h"
#include"enemy.h"
#include"game.h"

#include"scenemanager.h"

#include<QGraphicsScene>
#include<QList>

extern Game* game;
extern Scenemanager* scenemanager;

Tower_player::Tower_player(QGraphicsItem* parent) : QObject(), QGraphicsPixmapItem(parent)
{
    //initialize the tower HP
    tower_HP=100000;
    tower_attack = 1000;
    tower_atk_range = 200+this->x();

    //set position
    setPos(24,286);

    //draw the towers
    setPixmap(QPixmap(":/picture/tower_player.png"));

    //being attack
    QTimer* timer_player_tower_move = new QTimer(this);
    connect(timer_player_tower_move,SIGNAL(timeout()),this,SLOT(attack()));
    timer_player_tower_move -> start(1000);
}

void Tower_player::decrease_the_battle_time()
{
    //game->time_battle->time_decrease();
    scenemanager->game->time_battle->time_decrease();
}
void Tower_player::increase_the_money()
{
    //game->money->money_increase();
    scenemanager->game->money->money_increase();
}

void Tower_player::attack()
{
    //search enemy
    int stop_flag=0;
    foreach(Enemy* minion,scenemanager->game->list_enemy)
    {
        if(abs(this->x() - minion->x()) <= tower_atk_range)
        {
            stop_flag=1;
            minion->decrease_enemy_HP(tower_attack);
        }
    }
}

void Tower_player::decrease_tower_HP(int decrease_number)
{
    tower_HP = tower_HP-decrease_number;
    scenemanager->game->hp_tower_player->show_hp_tower(1);  //1:player
    if(tower_HP<=0)
    {
        //remove tower from game
        scenemanager->game->removeItem(this);
        delete this;
        //send data out to calculate score
        scenemanager->battle_status = 2;
        //game end, clear everything
        scenemanager->game->clear();

        //change scene to 2
        scenemanager->changescene(2);
    }
}

int Tower_player::get_tower_HP()
{
    return tower_HP;
}

