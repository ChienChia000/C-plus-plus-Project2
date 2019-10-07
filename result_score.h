#ifndef RESULT_SCORE_H
#define RESULT_SCORE_H

#include<QGraphicsTextItem>

class Result_score : public QGraphicsTextItem
{
public:
    Result_score(QGraphicsItem* parent=0, int type=0);
    void increase_score();
private:
    int score;
};

#endif // RESULT_SCORE_H
