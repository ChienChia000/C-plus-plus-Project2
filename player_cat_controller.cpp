#include "player_cat_controller.h"

#include"scenemanager.h"
#include"enemy.h"
#include"game.h"
#include"tower_enemy.h"

#include<stdlib.h>  //rand()
#include<QTimer>
#include<QGraphicsScene>
#include<QVector>
#include<QtMath>
#include<QList>

#include<QFont>
#include<QGraphicsTextItem>

extern Scenemanager* scenemanager;
extern Game* game;

Player_cat_controller::Player_cat_controller(int cat_number):QObject(), QGraphicsPixmapItem()
{
    //set the type
    cat_type = cat_number;

    //create little cat
    if(cat_number == 1)
    {
        cat_width = 99;
        cat_hight = 99;

        cat_HP = 3000;
        cat_attack = 10;
        cat_atk_range = cat_width+20;
        cat_speed = 15;

        hp_minion = new HP_minion(this, cat_HP);
        hp_minion->setPos(25,-25);
        //set the cat position
        cat_beging_pos = rand()%20;
        setPos(193,406+cat_beging_pos);
        setPixmap(QPixmap(":/picture/minon_player_littlecat.png"));
    }
    //create wall cat
    else if(cat_number == 2)
    {
        cat_width = 81;
        cat_hight = 135;

        cat_hight = 135;
        cat_HP = 25000;
        cat_attack = 5;
        cat_atk_range = cat_width+10;
        cat_speed = 20;

        hp_minion = new HP_minion(this, cat_HP);
        hp_minion->setPos(7,-25);
        //set the cat position
        cat_beging_pos = rand()%20;
        setPos(193,371+cat_beging_pos);
        setPixmap(QPixmap(":/picture/minon_player_wallcat.png"));
    }
    //create dragon cat
    else if(cat_number == 3)
    {
        cat_width = 152;
        cat_hight = 250;

        cat_HP = 10000;
        cat_attack = 100;
        cat_atk_range = cat_width+70;
        cat_speed = 30;

        hp_minion = new HP_minion(this, cat_HP);
        hp_minion->setPos(50,-25);
        //set the cat position
        cat_beging_pos = rand()%20;
        setPos(193,265+cat_beging_pos);
        setPixmap(QPixmap(":/picture/minon_player_dragoncat.png"));
    }
    else if(cat_number == 4)	//create giant cat
    {
        cat_width = 160;
        cat_hight = 305;

        cat_HP = 15000;
        cat_attack = 150;
        cat_atk_range = cat_width+50;
        cat_speed = 55;

        hp_minion = new HP_minion(this, cat_HP);
        hp_minion->setPos(45,-25);
        //set the cat position
        cat_beging_pos = rand()%20;
        setPos(193,200+cat_beging_pos);
        setPixmap(QPixmap(":/picture/minon_player_giantcat.png"));
    }
    //put the cat into the list
    scenemanager->game->list_player.push_back(this);

    QTimer* timer_cat = new QTimer();
    connect(timer_cat,SIGNAL(timeout()),this,SLOT(player_cat_move()));
    //start the timer
    timer_cat->start(cat_speed);
}

void Player_cat_controller::player_cat_move()
{
    //search enemy
    int stop_flag=0;
    foreach(Enemy* minion,scenemanager->game->list_enemy)
    {
        if(abs(this->x() - minion->x()) <= cat_atk_range)
        {
            stop_flag=1;
            minion->decrease_enemy_HP(cat_attack);
        }
    }
    if(abs(scenemanager->game->tower_enemy->x() - this->x()) <= cat_atk_range)
    {
        stop_flag=1;
        scenemanager->game->tower_enemy->decrease_tower_HP(cat_attack);
    }
    if(stop_flag == 0)
    {
        //move the cat
        if(pos().x()<1050)
        {
            setPos(x()+1,y());
        }
    }
}

void Player_cat_controller::player_cat_decreaseHP(int decrease_number)
{
    cat_HP=cat_HP-decrease_number;
    this->hp_minion->setPlainText(QString::number(cat_HP));
    if(cat_HP<=0)
    {
        //remove the enemy form scene
        scenemanager->game->list_player.removeOne(this);
        scenemanager->game->removeItem(this);
        //delete the enemy
        delete this;
        return;
    }
}

int Player_cat_controller::get_player_cat_HP()
{
    return cat_HP;
}

int Player_cat_controller::get_cat_width()
{
    return cat_width;
}
int Player_cat_controller::get_cat_hight()
{
    return cat_hight;
}
