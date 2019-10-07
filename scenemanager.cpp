#include "scenemanager.h"

Scenemanager::Scenemanager():QGraphicsView()
{
    battle_status = 0;
    battle_score = 0;
    battle_time = 0;
    tower_left_HP = 0;
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,720);
    //create the first scene
    start = new Start();
    //game = new Game();
    setScene(start);
}

void Scenemanager::changescene(int num)
{
    scenenumber = num;
    if(scenenumber==1)
    {
        start->start_music->stop();
        start->clear();
        game = new Game();
        setScene(game);
    }
    if(scenenumber==2)
    {
        game->battle_music->stop();
        result = new Result();
        setScene(result);
    }
}
int Scenemanager::get_scenenum()
{
    return scenenumber;
}
