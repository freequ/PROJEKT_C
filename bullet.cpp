#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"

#include <QDebug>
Bullet::Bullet(): QObject(), QGraphicsRectItem(){
    // RYSOWANIE POCISKU
    setRect(0,0,30,30);

    // polączenie z timerem
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move(){
    // SPOTKANIE POCISKU Z PRZECIWNIKIEM (USUWA OBA)
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // usunięcie obywdu
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // usunięcie obywdu
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // ruch pocisku w góre
    setPos(x(),y()-10);
    if (pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
