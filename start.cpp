#include "start.h"
#include"scenemanager.h"

#include<QBrush>
#include<QImage>
#include<QImage>

extern Scenemanager* scenemanager;

Start::Start(QWidget* parent)
{
    setSceneRect(0,0,1280,720);
    setBackgroundBrush(QBrush(QImage(":/picture/startscene.png")));

    Start_button* start_button = new Start_button();
    addItem(start_button);

    //add background music
    start_music = new QMediaPlayer();
    start_music->setMedia(QUrl("qrc:/music/scene_start.mp3"));
    start_music->play();
}

void Start::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
    {
        scenemanager->changescene(1);
    }
}
