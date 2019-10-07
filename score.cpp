#include "score.h"

#include<QFont>
#include"game.h"

#include"scenemanager.h"

extern Game* game;
extern Scenemanager* scenemanager;

Score::Score(QGraphicsItem* parent) : QGraphicsTextItem(parent)
{
    //initial the money to 0
    score = 0;

    //draw the text
    setPlainText(QString("Score: ")+QString::number(score));    //Score: 0 $
    setDefaultTextColor(Qt::white);
    setPos(x()+540,y());
    setFont(QFont("main",27));
}

void Score::score_increase(int add_number)
{
    score =score+add_number;
    setPlainText(QString("Score: ")+QString::number(score));
}

int Score::get_score()
{
    return score;
}
