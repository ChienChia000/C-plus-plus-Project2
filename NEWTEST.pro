#-------------------------------------------------
#
# Project created by QtCreator 2017-05-14T15:14:54
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NEWTEST
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    tower_enemy.cpp \
    tower_player.cpp \
    enemy.cpp \
    time_battle.cpp \
    money.cpp \
    icon_littlecat.cpp \
    icon_wallcat.cpp \
    player_cat_controller.cpp \
    icon_dragoncat.cpp \
    icon_giantcat.cpp \
    start.cpp \
    scenemanager.cpp \
    start_button.cpp \
    score.cpp \
    result.cpp \
    result_score.cpp \
    hp_tower.cpp \
    hp_minion.cpp

HEADERS  += \
    game.h \
    tower_enemy.h \
    tower_player.h \
    enemy.h \
    time_battle.h \
    money.h \
    icon_littlecat.h \
    icon_wallcat.h \
    player_cat_controller.h \
    icon_dragoncat.h \
    icon_giantcat.h \
    start.h \
    scenemanager.h \
    start_button.h \
    score.h \
    result.h \
    result_score.h \
    hp_tower.h \
    hp_minion.h

FORMS    += mainwindow.ui

RESOURCES += \
    resourse.qrc
