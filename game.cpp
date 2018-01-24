#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QThread>
#include "garage.h"
#include <QDebug>

extern Garage * garage;

Game::Game(GlobalScore * gls, QApplication * qap, QWidget * parent)
{
    //Ustawienie wartości zmiennych
    framerate = 60;
    framedist = 300/framerate;
    windowxsize = 800;
    windowysize = 600;
    playerxsize = 50;
    playerysize = 100;
    bulletxsize = 10;
    bulletysize = 10;
    enemyxsize = 50;
    enemyysize = 100;

    this->gls = gls;
    this->qap = qap;
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,windowxsize,windowysize);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(windowxsize,windowysize);
    pixmap = new QPixmap;
    pixmap->load("C:/Users/kloso_000/Documents/NFS/bg.png");
    scene->setBackgroundBrush(pixmap->scaled(windowxsize,2*windowysize,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    // tworzy gracza
    player = new Player(this);
    player->setRect(0,0,playerxsize,playerysize); // rozdzielczość gracza
    player->setPos(windowxsize/2,windowysize - playerysize); // ustawia pozycje startową na środku
    // ustawia odniesienie ekranu do gracza
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // dodaje gracza do sceny
    scene->addItem(player);

    // tworzy wynik / zdrowie
    score = new Score(this);
    scene->addItem(score);
    health = new Health(this);
    health->setPos(health->x(),health->y()+45);
    scene->addItem(health);
    espawner = new EnemySpawner(this);

    show();

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(play()));
    timer->start(framedist);
}

Game::~Game()
{
    delete pixmap;
    delete espawner;
    delete timer;
    scene->clear();
    delete scene;
}

void Game::end()
{
    gls->globalScore += score->score;
    //qap->exit(0);
    garage = new Garage(gls, qap);
    garage->show();
    delete this;
}

void Game::play()
{
    qDebug() << "Jestem w play";
    static double scrolled = 0;
    if(scrolled == windowysize)
    {
       pixmap->scroll(0,-(int)windowysize,pixmap->rect());
       scrolled = 0;
    };
    pixmap->scroll(0,8,pixmap->rect());
    scene->setBackgroundBrush(*pixmap);
    scrolled+=300;
    if(health->getHealth() == 0)
        end();
}
