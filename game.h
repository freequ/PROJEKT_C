#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "enemyspawner.h"
#include "globalscore.h"
#include <QTimer>
#include <QApplication>
#include <QObject>

class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game(GlobalScore* gls, QApplication * qap, QWidget * parent=0);
    ~Game();
    void end();
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    EnemySpawner * espawner;
    GlobalScore * gls;
    QTimer * timer;
    QApplication * qap;
    QPixmap * pixmap;

    double framerate;
    double framedist;
    double windowxsize;
    double windowysize;
    double playerxsize;
    double playerysize;
    double bulletxsize;
    double bulletysize;
    double enemyxsize;
    double enemyysize;
public slots:
    void play();
};

#endif
