#ifndef ICON_WALLCAT_H
#define ICON_WALLCAT_H

#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QObject>

class Icon_wallcat : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Icon_wallcat(QGraphicsItem* parent=0);
    void spawn_wallcat();
};

#endif // ICON_WALLCAT_H
