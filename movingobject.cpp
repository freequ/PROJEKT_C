#include "movingobject.h"
#include "game.h"


template <class T>
T max(T o1, T o2)
{
    return o2 > o1? o2:o1;
}

template <class T>
T min(T o1, T o2)
{
    return o2 < o1? o2:o1;
}

MovingObject::MovingObject(Game * game, QGraphicsItem *parent): QGraphicsRectItem(parent){
    up_boundary = left_boundary = 0;
    this -> game = game;
    down_boundary = game->windowysize;
    right_boundary = game->windowxsize;
    pixmap = new QPixmap();
    pixmap->load("C:/Users/kloso_000/Documents/NFS/bg2.png");
    setBrush(pixmap->scaled(game->playerxsize,game->playerysize));
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(game->framedist);
}

MovingObject::~MovingObject()
{
    delete timer;
}

void MovingObject::update()
{
    move();
}

void MovingObject::move()
{
     setPos(x()+velocity_x*game->framedist,y()+velocity_y*game->framedist);
     if (pos().y() + rect().height() + transformOriginPoint().y() < up_boundary){
         emit UpBoundaryExceed();

     }
     if (pos().y() - transformOriginPoint().y() > down_boundary){
         emit DownBoundaryExceed();
     }

     if (pos().x() - transformOriginPoint().x() < left_boundary){
         emit LeftBoundaryExceed();
     }

     if (pos().x() - transformOriginPoint().x() + rect().width() > right_boundary){
         emit RightBoundaryExceed();
     }
}
