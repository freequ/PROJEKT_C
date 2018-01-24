#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>
#include "movingobject.h"

class Bullet: public MovingObject{
    Q_OBJECT
public:
    Bullet(Game * game);
public slots:
    void update();
    void destroy();
};

#endif
