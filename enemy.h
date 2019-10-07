#ifndef ENEMY_H
#define ENEMY_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QGraphicsItem>
#include"hp_minion.h"

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(int enemy_type=0, QGraphicsItem* parent=0);
    HP_minion* hp_minion;
public slots:
    void move();
    void decrease_enemy_HP(int decrease_enemy);
    int get_enemy_HP();
private:
    int enemytype;

    int enemy_HP;
    int enemy_attack;
    int enemy_attack_range;
    int enemy_speed;

    int enemy_begin_pos;
    int points;

};

#endif // ENEMY_H
