#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

#include <QDebug>
Enemy::Enemy(): QObject(), QGraphicsRectItem(){
    //ustalanie randomowych pozycji przeciwników
    int random_number = rand() % 700;
    setPos(random_number,0);

    // rysowanie przeciwnikow
    setRect(0,0,100,100);

    // połączenie z tierem
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move(){
    // poruszanie przeciwników w dół
    setPos(x(),y()+5);
    if (pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
