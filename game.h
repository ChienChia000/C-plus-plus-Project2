#ifndef GAME_H
#define GAME_H

#include<QWidget>
#include<QGraphicsScene>
#include<QGraphicsTextItem>
#include<QGraphicsPixmapItem>
#include<QTimer>
#include<QVector>
#include<QMediaPlayer>

#include"start.h"

#include"tower_enemy.h"
#include"tower_player.h"

#include"time_battle.h"
#include"money.h"
#include"score.h"
#include"hp_tower.h"

#include"player_cat_controller.h"
#include"enemy.h"
#include"icon_littlecat.h"
#include"icon_wallcat.h"
#include"icon_dragoncat.h"
#include"icon_giantcat.h"


class Game : public QGraphicsScene
{
public:
    Game(QWidget *parent=0);

    QMediaPlayer* battle_music;

    Tower_enemy* tower_enemy;
    Tower_player* tower_player;

    QTimer* timer_spawn;
    QTimer* timer_time;
    QTimer* timer_money;

    Time_battle* time_battle;
    Money* money;
    Score* score;
    HP_tower* hp_tower_enemy;
    HP_tower* hp_tower_player;

    Icon_littlecat* icon_littlecat;
    Icon_wallcat* icon_wallcat;
    Icon_dragoncat* icon_dragoncat;
    Icon_giantcat* icon_giantcat;

    QVector<Player_cat_controller*> list_player;
    QVector<Enemy*> list_enemy;

    void keyPressEvent(QKeyEvent * event);
};

#endif // GAME_H
