#include "garage.h"
#include <QKeyEvent>
#include <QDebug>
#include "game.h"

extern Game * game;

Garage::Garage(GlobalScore * gls, QApplication * qap, QWidget *parent)
{
    qDebug() << "Jestem w garażu";
    this -> gls = gls;
    this -> qap = qap;
    windowxsize = 800;
    windowysize = 600;
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,windowxsize,windowysize);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(windowxsize,windowysize);
    pixmap = new QPixmap;
    pixmap->load("C:/Users/kloso_000/Documents/NFS/mech.png");
    scene->setBackgroundBrush(pixmap->scaled(windowxsize,windowysize,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    this->setFocus();
    gdesc = new GarageDescription(gls);
    scene->addItem(gdesc);

}

void Garage::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Q:
        gls->TryImprove(gls->Trait::HEALTH);
        break;
    case Qt::Key_W:
        gls->TryImprove(gls->Trait::TURNACCELARATION);
        break;
    case Qt::Key_E:
        gls->TryImprove(gls->Trait::ENEMYSPEED);
        break;
    case Qt::Key_R:
        gls->TryImprove(gls->Trait::WEAPONCOOLDOWN);
        break;
    case Qt::Key_Escape:
        QuitApp();
        return;
    case Qt::Key_B:
        EnterGame();
        return;
    }
    gdesc->UpdateDescription();
    qDebug() << "Jestem w keyPressedEvent\n";
}

Garage::~Garage()
{
    scene->clear();
    delete scene;
}

void Garage::EnterGame()
{
    game = new Game(gls,qap);
    game->show();
    delete this;
}

void Garage::QuitApp()
{
    qap->exit();
}


