#include "tower_enemy.h"
#include"enemy.h"
#include"game.h"

#include<stdlib.h>  //rand()
#include<QGraphicsScene>
#include<QTimer>
#include<QList>

#include"scenemanager.h"

extern Game* game;
extern Scenemanager* scenemanager;

Tower_enemy::Tower_enemy(QGraphicsItem* parent) : QObject(), QGraphicsPixmapItem(parent)
{
    tower_HP = 100000;
    tower_attack = 1000;
    tower_atk_range = 100;

    spawn_type = 0;
    //set position
    setPos(1088,286);

    //draw the towers
    setPixmap(QPixmap(":/picture/tower_enemy.png"));

    //search player
    QTimer* timer_enemy_tower_move = new QTimer(this);
    connect(timer_enemy_tower_move,SIGNAL(timeout()),this,SLOT(attack()));
    timer_enemy_tower_move->start(1000);
}

void Tower_enemy::spawn()   //spawn an enemy
{
    //if(game->time_battle->get_time_battle() >= 0)
    if(scenemanager->game->time_battle->get_time_battle() >= 0)
    {
        //create an random enemy
        spawn_type = rand()%4 + 1;
        Enemy * enemy = new Enemy(spawn_type);
        //game->scene_battle -> addItem(enemy);
        scenemanager->game->addItem(enemy);
    }
}

void Tower_enemy::attack()
{
    //search player cat
    int stop_flag=0;
    foreach(Player_cat_controller* player,scenemanager->game->list_player)
    {
        if(abs(this->x() - player->x()-99) <= tower_atk_range)
        {
            stop_flag=1;
            player->player_cat_decreaseHP(tower_attack);
        }
    }
}

void Tower_enemy::decrease_tower_HP(int decrease_number)
{
    tower_HP=tower_HP-decrease_number;
    scenemanager->game->hp_tower_enemy->show_hp_tower(2);   //2:enemy
    if(tower_HP<=0)
    {
        //remove tower from game
        scenemanager->game->removeItem(this);
        delete this;
        //increase score
        scenemanager->game->score->score_increase(10000);
        //send data out to calculate score
        scenemanager->battle_time = scenemanager->game->time_battle->get_time_battle();
        scenemanager->battle_score = scenemanager->game->score->get_score();
        scenemanager->tower_left_HP = scenemanager->game->tower_player->get_tower_HP();
        scenemanager->battle_status = 1;
        //game end, clear everything
        scenemanager->game->clear();
        //change scene to 2
        scenemanager->changescene(2);
        return;
    }
}
int Tower_enemy::get_tower_HP()
{
    return tower_HP;
}
