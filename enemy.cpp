#include "enemy.h"

#include<stdlib.h>
#include<QTimer>
#include<QGraphicsScene>
#include<QList>

#include"game.h"
#include"scenemanager.h"

extern Game* game;
extern Scenemanager* scenemanager;

Enemy::Enemy(int enemy_type, QGraphicsItem* parent) : QObject(), QGraphicsPixmapItem(parent)
{
    enemytype = enemy_type;
    if(enemytype == 1)
    {
        enemy_HP = 3000;
        enemy_attack = 5;
        enemy_attack_range = 20;
        enemy_speed = 15;
        points = 200;

        hp_minion = new HP_minion(this, enemy_HP);
        hp_minion->setPos(25,-25);
        //draw the enemy
        enemy_begin_pos = rand()%20;
        setPos(988,406+enemy_begin_pos);
        setPixmap(QPixmap(":/picture/minon_enemy_littlecat.png"));
    }
    else if(enemytype == 2)
    {
        enemy_HP = 25000;
        enemy_attack = 5;
        enemy_attack_range = 10;
        enemy_speed = 20;
        points = 500;

        hp_minion = new HP_minion(this, enemy_HP);
        hp_minion->setPos(7,-25);
        //draw the enemy
        enemy_begin_pos = rand()%20;
        setPos(988,371+enemy_begin_pos);
        setPixmap(QPixmap(":/picture/minon_enemy_wallcat.png"));
    }
    else if(enemytype == 3)
    {
        enemy_HP = 10000;
        enemy_attack = 100;
        enemy_attack_range = 70;
        enemy_speed = 30;
        points = 1500;

        hp_minion = new HP_minion(this, enemy_HP);
        hp_minion->setPos(50,-25);
        //draw the enemy
        enemy_begin_pos = rand()%20;
        setPos(935,265+enemy_begin_pos);
        setPixmap(QPixmap(":/picture/minon_enemy_dragoncat.png"));
    }
    else if(enemytype == 4)
    {
        enemy_HP = 15000;
        enemy_attack = 150;
        enemy_attack_range = 50;
        enemy_speed = 55;
        points = 2000;

        hp_minion = new HP_minion(this, enemy_HP);
        hp_minion->setPos(45,-25);
        //draw the enemy
        enemy_begin_pos = rand()%20;
        setPos(927,200+enemy_begin_pos);
        setPixmap(QPixmap(":/picture/minon_enemy_giantcat.png"));
    }
    //make a timer to move the enemy
    QTimer* timer_enemy_walk = new QTimer(this);
    connect(timer_enemy_walk,SIGNAL(timeout()),this,SLOT(move()));
    //start a timer
    timer_enemy_walk->start(enemy_speed);
    //put it into the enemy vector
    scenemanager->game->list_enemy.push_back(this);
}

void Enemy::move()
{
    //search player cat
    int stop_flag=0;
    foreach(Player_cat_controller* player,scenemanager->game->list_player)
    {
        if(abs(this->x() - player->x() - player->get_cat_width()) <= enemy_attack_range)
        {
            stop_flag=1;
            player->player_cat_decreaseHP(enemy_attack);
        }
    }
    if(abs(scenemanager->game->tower_player->x() + 140 - this->x()) <= enemy_attack_range)
    {
        stop_flag=1;
        scenemanager->game->tower_player->decrease_tower_HP(enemy_attack);
    }
    if(stop_flag == 0)
    {
        //move the enemy left
        if(pos().x()>140)
        {
            setPos(x()-1,y());
        }
    }
}

void Enemy::decrease_enemy_HP(int decrease_enemy)
{
    enemy_HP = enemy_HP-decrease_enemy;
    this->hp_minion->setPlainText(QString::number(enemy_HP));
    if(enemy_HP<=0)
    {
        //remove the enemy form scene
        scenemanager->game->list_enemy.removeOne(this);
        scenemanager->game->removeItem(this);
        //delete the enemy
        delete this;
        //add the score
        scenemanager->game->score->score_increase(points);
        return;
    }
}

int Enemy::get_enemy_HP()
{
    return enemy_HP;
}

