#ifndef HP_TOWER_H
#define HP_TOWER_H

#include<QGraphicsTextItem>

class HP_tower : public QGraphicsTextItem
{
public:
    HP_tower(QGraphicsItem* parent=0);
    void show_hp_tower(int type=0);
    int get_hp_tower();
private:
    int hp_tower;
};

#endif // HP_ENEMY_TOWER_H
