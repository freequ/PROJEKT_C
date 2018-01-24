#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>
#include "Bullet.h"
#include "Enemy.h"
#include "game.h"
#include "gun.h"

//extern Game * game;

template <class T>
T max(T o1, T o2)
{
    return o2 > o1? o2:o1;
}

template <class T>
T min(T o1, T o2)
{
    return o2 < o1? o2:o1;
}

Player::Player(Game * game): MovingObject(game){
    velocity_x = velocity_y = 0;
    acceleration_x = game->gls->startTurnAcceleration;
    acceleration_y = 0;
    maxvelocity_x = 0.500;
    maxvelocity_y = 0;
    frictionloss = 0.001;
    gun = new Gun(this);
    lkey=rkey=ukey=dkey=skey= false;

    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    connect(this, SIGNAL(LeftBoundaryExceed()),this, SLOT(adjustposleft()));
    connect(this, SIGNAL(RightBoundaryExceed()),this, SLOT(adjustposright()));
}

void Player::keyPressEvent(QKeyEvent *event){
    switch (event->key())
    {
        case Qt::Key_Left: lkey = true; break;
        case Qt::Key_Right: rkey = true; break;
        case Qt::Key_Up: ukey = true; break;
        case Qt::Key_Down: dkey = true; break;
        case Qt::Key_Space: skey = true; break;
    }

}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Left: lkey = false; break;
        case Qt::Key_Right: rkey = false; break;
        case Qt::Key_Up: ukey = false; break;
        case Qt::Key_Down: dkey = false; break;
        case Qt::Key_Space: skey = false; break;
    }

}

void Player::update()
{
    if(velocity_x < 0)
        velocity_x = min(velocity_x +frictionloss*game->framedist, 0.0);
    else
        velocity_x = max(velocity_x -frictionloss*game->framedist, 0.0);

    if(velocity_y < 0)
        velocity_y = min(velocity_y + frictionloss*game->framedist, 0.0);
    else
        velocity_y = max(velocity_y -frictionloss*game->framedist, 0.0);

    if (lkey && !rkey){
        velocity_x = max(velocity_x - acceleration_x*game->framedist,-maxvelocity_x);
    }
    else if (!lkey && rkey){
        velocity_x = min(velocity_x + acceleration_x*game->framedist,maxvelocity_x);
    }

    if (dkey && !ukey){
        velocity_y = max(velocity_y - acceleration_y*game->framedist,-maxvelocity_y);
    }
    else if (!dkey && ukey){
        velocity_y = min(velocity_y + acceleration_y*game->framedist,maxvelocity_y);
    }
    if (skey){
        gun->try_shoot();

    }
}
void Player::adjustposleft()
{
      setPos(left_boundary, y());
}


void Player::adjustposright()
{
      setPos(right_boundary-game->playerxsize, y());
}


