#include "icon_dragoncat.h"

#include"game.h"
#include"money.h"
#include"player_cat_controller.h"
#include<QGraphicsScene>

#include"scenemanager.h"

extern Game* game;
extern Scenemanager* scenemanager;

Icon_dragoncat::Icon_dragoncat(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem()
{
    //set the icon position
    setPos(681,593);

    //draw the icon
    setPixmap(QPixmap(":/picture/icon_dragoncat_base.png"));
}

void Icon_dragoncat::spawn_dragoncat()
{
    //create an dragoncat
    Player_cat_controller * player_cat_controller = new Player_cat_controller(3);
    scenemanager->game->addItem(player_cat_controller);
}
