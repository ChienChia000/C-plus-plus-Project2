#include "result.h"

#include"scenemanager.h"
#include"result_score.h"

#include<QBrush>
#include<QImage>

extern Scenemanager* scenemanager;

Result::Result(QWidget *parent)
{
    setSceneRect(0,0,1280,720);
    setBackgroundBrush(QBrush(QImage(":/picture/end_scene.png")));

    //set result background music
    music_result = new QMediaPlayer();
    music_result->setMedia(QUrl("qrc:/music/scene_result.mp3"));
    music_result->play();

    if(scenemanager->battle_status == 1)    //win
    {
        Result_score* score = new Result_score(0,1);
        Result_score* towerHP = new Result_score(0,2);
        Result_score* time = new Result_score(0,3);
        Result_score* total = new Result_score(0,4);
        addItem(score);
        addItem(towerHP);
        addItem(time);
        addItem(total);
    }
    else if(scenemanager->battle_status == 2)   //lose
    {
        Result_score* lose = new Result_score(0,6);
        addItem(lose);
    }
    else if(scenemanager->battle_status == 0)   //tie
    {
        Result_score* tie = new Result_score(0,5);
        addItem(tie);
    }
}
