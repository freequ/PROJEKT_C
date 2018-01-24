#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H

#include "enemy.h"
#include <QObject>
#include <QTimer>
#include <list>

class EnemySpawner : public QObject
{
    Q_OBJECT
public:
    EnemySpawner(Game * game);
    virtual ~EnemySpawner();
public slots:
    void update();
protected:
    void spawn();
    double losstime;
    double spawntime;
    QTimer * timer;
    Game * game;
};

#endif // ENEMYSPAWNER_H
