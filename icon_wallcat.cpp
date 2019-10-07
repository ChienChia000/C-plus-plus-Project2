#include"player_cat_controller.h"

#include"game.h"
#include"money.h"
#include<player_cat_controller.h>
#include<QGraphicsScene>

#include"scenemanager.h"

extern Game* game;
extern Scenemanager* scenemanager;

Icon_wallcat::Icon_wallcat(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem()
{
    //set the icon position
    setPos(457,593);

    //draw the icon
    setPixmap(QPixmap(":/picture/icon_wallcat_base.png"));
}
void Icon_wallcat::spawn_wallcat()
{
    //create an wallcat
    Player_cat_controller* player_cat_controller = new Player_cat_controller(2);
    scenemanager->game->addItem(player_cat_controller);
}
