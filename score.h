#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
class Game;

class Score: public QGraphicsTextItem{
public:
    friend class Game;
    Score(Game * game, QGraphicsItem * parent=0);
    void increase();
    int getScore();
private:
    int score;
    Game * game;
};

#endif
