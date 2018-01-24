#ifndef HEALTH_H
#define HEALTH_H


#include <QGraphicsTextItem>
class Game;

class Health: public QGraphicsTextItem{
public:
    Health(Game * game, QGraphicsItem * parent=0);
    void decrease();
    int getHealth();
private:
    int health;
    Game * game;
};

#endif
