#include <QApplication>
#include "MyRect.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>


int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    // tworzenie SCENY
    QGraphicsScene * scene = new QGraphicsScene();

    // Tworzenie przedmiotów do dodania w SCENIE
    MyRect * player = new MyRect();
    player->setRect(0,0,100,100);

    // dodawanie przedmiotów do Sceny
    scene->addItem(player);

    // ustawianie focusu na graczu
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // tworzenie sceny
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // rysowanie sceny
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    player->setPos(view->width()/2,view->height() - player->rect().height());

    // tworzenie przeciwników
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    return a.exec();
}
