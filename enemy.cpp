#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Game.h"
#include <QDebug>


Enemy::Enemy(Game * game): MovingObject(game){
    //ustawia losowa pozycje
    int random_number = rand() % 700;
    setPos(random_number,0);
    // rysuje przeciwnikow
    setRect(0,0,game->enemyxsize,game->enemyysize);
    velocity_y = game->gls->startEnemySpeed;

    // zamienia czas na punkty
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    connect(this, SIGNAL(DownBoundaryExceed()), this, SLOT(destroy()));
}

void Enemy::destroy()
{
    qDebug() << "Jestem w dstroy";
    game->score->increase();
    game->scene->removeItem(this);
    delete this;
}

void Enemy::update()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            game->health->decrease();

            scene()->removeItem(this);

            delete this;
            return;
        }
    }
}
