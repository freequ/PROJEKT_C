#include "Health.h"
#include <QFont>
#include "game.h"

Health::Health(Game * game,QGraphicsItem *parent): QGraphicsTextItem(parent){
    this-> game = game;
    health = game->gls->startHealth;

    setPlainText(QString("Zdrowie: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Tahoma",30));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Zdrowie: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",30));
}

int Health::getHealth(){
    return health;
}
