#include "hp_minion.h"
#include"scenemanager.h"

#include<QFont>

extern Scenemanager* scenemanager;

HP_minion::HP_minion(QGraphicsItem* parent, int initial) : QGraphicsTextItem(parent)
{
    //draw the text
    setPlainText(QString::number(initial));    //HP: 3000
    setDefaultTextColor(Qt::red);
    setFont(QFont("main",15));
}
