#include "Score.h"
#include <QFont>

Score::Score(Game  * game, QGraphicsItem *parent): QGraphicsTextItem(parent){
    score = 0;
    this -> game = game;
    setPlainText(QString("Wynik: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::white);
    setFont(QFont("Tahoma",30));
}

void Score::increase(){
    score++;
    setPlainText(QString("Wynik: ") + QString::number(score)); // Score: 1
}

int Score::getScore(){
    return score;
}
