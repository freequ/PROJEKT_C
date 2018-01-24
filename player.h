#ifndef PLAYER_H
#define PLAYER_H

#include "movingobject.h"
class Gun;

class Player : public MovingObject
{
    Q_OBJECT
public:
    friend class Gun;
    Player(Game * game);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
public slots:
    void update();
    void adjustposleft();
    void adjustposright();
private:
    bool lkey,rkey,ukey,dkey,skey;
    Gun * gun;
};

#endif
