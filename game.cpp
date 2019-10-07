#include"game.h"
#include"scenemanager.h"

#include<QBrush>
#include<QImage>
#include <QKeyEvent>

extern Scenemanager* scenemanager;

Game::Game(QWidget* parent)
{   
    //create the battle scene
    setSceneRect(0,0,1280,720);
    setBackgroundBrush(QBrush(QImage(":/picture/battlefield.png")));

    //add background music
    battle_music = new QMediaPlayer();
    battle_music->setMedia(QUrl("qrc:/music/scene_battle.mp3"));
    battle_music->play();

    //create two towers
    tower_enemy = new Tower_enemy();
    tower_player = new Tower_player();
    addItem(tower_enemy);
    addItem(tower_player);

    //create hp_tower on scene
    hp_tower_player = new HP_tower();
    hp_tower_enemy = new HP_tower();
    addItem(hp_tower_player);
    addItem(hp_tower_enemy);
    hp_tower_player->setPos(0,250);
    hp_tower_enemy->setPos(1060,250);

    //spawn the enemy
    timer_spawn = new QTimer();
    QObject::connect(timer_spawn,SIGNAL(timeout()),tower_enemy,SLOT(spawn()));
    timer_spawn->start(6500);

    //create the time
    time_battle = new Time_battle();
    //scene_battle -> addItem(time_battle);
    addItem(time_battle);
    timer_time = new QTimer();
    timer_time->start(1000);
    connect(timer_time,SIGNAL(timeout()),tower_player,SLOT(decrease_the_battle_time()));

    //create the money
    money = new Money();
    //scene_battle -> addItem(money);
    addItem(money);
    timer_money = new QTimer();
    timer_money->start(1000);
    connect(timer_money,SIGNAL(timeout()),tower_player,SLOT(increase_the_money()));

    //create the score
    score = new Score();
    addItem(score);

    //create the player cats icon / spawn palyer's cats
    icon_littlecat = new Icon_littlecat();
    icon_wallcat = new Icon_wallcat();
    icon_dragoncat = new Icon_dragoncat();
    icon_giantcat = new Icon_giantcat();
    addItem(icon_littlecat);
    addItem(icon_wallcat);
    addItem(icon_dragoncat);
    addItem(icon_giantcat);
}

void Game::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Z)
    {
        if(money->get_money()>=2)
        {
            //spawn littlecat
            icon_littlecat->spawn_littlecat();
            //minus money
            money -> money_decrease(2);
        }
    }
    if (event->key() == Qt::Key_X)
    {
        if(money->get_money()>=4)
        {
            //spawn wallcat
            icon_wallcat->spawn_wallcat();
            //minus money
            money->money_decrease(4);
        }
    }
    if (event->key() == Qt::Key_C)
    {
        if(money->get_money()>=6)
        {
            //spawn dragoncat
            icon_dragoncat -> spawn_dragoncat();
            //minus money
            money -> money_decrease(6);
        }
    }
    if (event->key() == Qt::Key_V)
    {
        if(money->get_money()>=9)
        {
            //spawn giantcat
            icon_giantcat -> spawn_giantcat();
            //minus money
            money -> money_decrease(9);
        }
    }
}
