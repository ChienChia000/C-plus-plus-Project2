#ifndef ICON_GIANTCAT_H
#define ICON_GIANTCAT_H

#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QObject>

class Icon_giantcat : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Icon_giantcat(QGraphicsItem* parent=0);
    void spawn_giantcat();
};

#endif // ICON_GIANTCAT_H
