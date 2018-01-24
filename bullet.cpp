#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"



Bullet::Bullet(Game * game): MovingObject(game){
    setRect(0,0,30,30);
    velocity_y = -0.900;


    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(this, SIGNAL(UpBoundaryExceed()),this, SLOT(destroy()));
}

void Bullet::update()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // dodaje punkty do wyniku
            game->score->increase();

            // usuwa ze sceny
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // usuwa ze stosu
            delete colliding_items[i];
            delete this;
            return;
        }
    }
}

void Bullet::destroy()
{
    scene()->removeItem(this);
    delete this;
}
