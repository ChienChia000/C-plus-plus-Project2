#ifndef TIME_BATTLE_H
#define TIME_BATTLE_H

#include<QGraphicsTextItem>

class Time_battle : public QGraphicsTextItem
{
public:
    Time_battle(QGraphicsItem* parent=0);
    void time_decrease();
    int get_time_battle();
private:
    int time;
};

#endif // TIME_BATTLE_H
