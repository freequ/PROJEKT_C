#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class Game;

class MovingObject : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    MovingObject(Game * game, QGraphicsItem * parent=0);
    ~MovingObject();
public slots:
    void update();
signals:
    void LeftBoundaryExceed();
    void RightBoundaryExceed();
    void UpBoundaryExceed();
    void DownBoundaryExceed();
public slots:
    void move();
protected:
    double up_boundary, down_boundary, right_boundary, left_boundary;
    double frictionloss;
    double acceleration_x, acceleration_y;
    double maxvelocity_x, maxvelocity_y;
    double velocity_x,velocity_y;
    Game * game;
    QTimer * timer;
    QPixmap * pixmap;
};

#endif // MOVINGOBJECT_H
