#include "icon_giantcat.h"

#include"game.h"
#include"money.h"
#include<player_cat_controller.h>
#include<QGraphicsScene>

#include"scenemanager.h"

extern Game* game;
extern Scenemanager* scenemanager;

Icon_giantcat::Icon_giantcat(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem()
{
    //set the icon position
    setPos(905,593);

    //draw the icon0
    setPixmap(QPixmap(":/picture/icon_giantcat_base.png"));
}

void Icon_giantcat::spawn_giantcat()
{
    //create an giantcat
    Player_cat_controller * player_cat_controller = new Player_cat_controller(4);
    scenemanager->game->addItem(player_cat_controller);
}
