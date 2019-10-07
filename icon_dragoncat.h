#ifndef ICON_DRAGONCAT_H
#define ICON_DRAGONCAT_H

#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QObject>

class Icon_dragoncat : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Icon_dragoncat(QGraphicsItem* parent=0);
    void spawn_dragoncat();
};

#endif // ICON_DRAGONCAT_H
