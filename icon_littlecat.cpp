#include "icon_littlecat.h"

#include"game.h"
#include"money.h"
#include"player_cat_controller.h"
#include<QGraphicsScene>

#include"scenemanager.h"

extern Game* game;
extern Scenemanager* scenemanager;

Icon_littlecat::Icon_littlecat(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem()
{
    //set the icon position
    setPos(233,593);

    //draw the icon0
    setPixmap(QPixmap(":/picture/icon_littlecat_base.png"));
}

void Icon_littlecat::spawn_littlecat()
{
    //create an littlecat
    Player_cat_controller * player_cat_controller = new Player_cat_controller(1);
    scenemanager->game->addItem(player_cat_controller);
}

