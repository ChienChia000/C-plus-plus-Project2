#ifndef START_H
#define START_H

#include"start_button.h"

#include<QWidget>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<QMediaPlayer>

class Start : public QGraphicsScene
{
public:
    Start(QWidget *parent=0);
    //QGraphicsScene* scene_start;
    void keyPressEvent(QKeyEvent * event);
    QMediaPlayer* start_music;
};

#endif // START_H
