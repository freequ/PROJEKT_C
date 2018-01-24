#include "enemyspawner.h"
#include "game.h"

//extern Game * game;

EnemySpawner::EnemySpawner(Game * game)
{
    spawntime = 500;
    losstime = 3;
    this -> game = game;
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(spawntime);
}

EnemySpawner::~EnemySpawner()
{
    delete timer;
}

void EnemySpawner::update()
{
    spawn();
    timer->stop();
    spawntime -= losstime;
    timer->start(spawntime);
}

void EnemySpawner::spawn()
{
 // tworzy przeciwnika
     Enemy * enemy = new Enemy(game);
     game->scene->addItem(enemy);
}
