#ifndef TOWER_PLAYER_H
#define TOWER_PLAYER_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QGraphicsItem>

class Tower_player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Tower_player(QGraphicsItem* parent=0);
    void decrease_tower_HP(int decrease_number);
    int get_tower_HP();
public slots:
    void decrease_the_battle_time();
    void increase_the_money();
    //void decrease_the_player_hp();

    void attack();
private:
    int tower_HP;
    int tower_attack;
    int tower_atk_range;
};

#endif // TOWER_PLAYER_H
