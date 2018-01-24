#ifndef GARAGE_H
#define GARAGE_H

#include <QObject>
#include "globalscore.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include "garagedescription.h"

class Garage : public QGraphicsView
{
public:
    Garage(GlobalScore * gls, QApplication * qap, QWidget *parent = 0);
    void keyPressEvent(QKeyEvent * event);
    ~Garage();
private:
    void EnterGame();
    void QuitApp();

    GlobalScore * gls;
    QApplication * qap;
    double windowxsize;
    double windowysize;
    QGraphicsScene * scene;
    GarageDescription * gdesc;
    QPixmap * pixmap;

};

#endif
