#ifndef RESULT_H
#define RESULT_H

#include<QWidget>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<QMediaPlayer>

class Result :public QGraphicsScene
{
public:
    Result(QWidget *parent=0);
    QMediaPlayer* music_result;
};

#endif // RESULT_H
