#ifndef PLAYER_CAT_CONTROLLER_H
#define PLAYER_CAT_CONTROLLER_H

#include<QObject>
#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QWidget>
#include"hp_minion.h"

class Player_cat_controller : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player_cat_controller(int cat_number=0);

    HP_minion* hp_minion;

public slots:
    void player_cat_move();
    void player_cat_decreaseHP(int decrease_number=0);
    int get_player_cat_HP();
    int get_cat_width();
    int get_cat_hight();
private:
    int cat_beging_pos;
    int cat_end_pos;
    int cat_speed;
    int cat_type;

    int cat_width;
    int cat_hight;

    int cat_attack;
    int cat_HP;
    int cat_atk_range;
};

#endif // PLAYER_CAT_CONTROLLER_H
