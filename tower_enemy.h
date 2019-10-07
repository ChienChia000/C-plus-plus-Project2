#ifndef TOWER_ENEMY_H
#define TOWER_ENEMY_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QGraphicsItem>

class Tower_enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Tower_enemy(QGraphicsItem* parent=0);
    void decrease_tower_HP(int decrease_number);
    int get_tower_HP();
public slots:
    void spawn();
    void attack();
private:
    int tower_HP;
    int tower_attack;
    int tower_atk_range;
    int spawn_type;
};

#endif // TOWER_ENEMY_H
