#ifndef ICON_LITTLECAT_H
#define ICON_LITTLECAT_H

#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QObject>

class Icon_littlecat : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Icon_littlecat(QGraphicsItem* parent=0);
    void spawn_littlecat();
};

#endif // ICON_LITTLECAT_H
