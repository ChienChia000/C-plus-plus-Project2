#ifndef START_BUTTON_H
#define START_BUTTON_H

#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QObject>

class Start_button : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Start_button(QGraphicsItem* parent=0);
public slots:
    void move();
};

#endif // START_BUTTON_H
