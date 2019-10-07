#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include<QGraphicsView>
#include<QKeyEvent>

#include"start.h"
#include"game.h"
#include"result.h"

class Scenemanager : public QGraphicsView
{
public:
    Scenemanager();

    Start* start;
    Game* game;    
    Result* result;

    void changescene(int num=0);
    int get_scenenum();
    int battle_score;
    int battle_time;
    int tower_left_HP;
    int battle_status;  //0:tie 1:win 2:lose
private:
    int scenenumber;
};

#endif // SCENEMANAGER_H
