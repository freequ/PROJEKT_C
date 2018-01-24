#-------------------------------------------------
#
# Project created by QtCreator 2018-01-16T00:07:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NFS
TEMPLATE = app


DEFINES += QT_DEPRECATED_WARNINGS




SOURCES += \
        main.cpp \
    Bullet.cpp \
    Enemy.cpp \
    Game.cpp \
    Health.cpp \
    Player.cpp \
    Score.cpp \
    movingobject.cpp \
    enemyspawner.cpp \
    gun.cpp \
    globalscore.cpp \
    garage.cpp \
    garagecontrol.cpp \
    garagedescription.cpp

HEADERS += \
    Bullet.h \
    Enemy.h \
    Game.h \
    Health.h \
    Player.h \
    Score.h \
    movingobject.h \
    enemyspawner.h \
    gun.h \
    globalscore.h \
    garage.h \
    garagecontrol.h \
    garagedescription.h

FORMS +=
