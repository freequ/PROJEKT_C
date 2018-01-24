#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include "movingobject.h"

class Enemy: public MovingObject{
    Q_OBJECT
public:
    Enemy(Game * game);
public slots:
    void destroy();
    void update();
};

#endif
