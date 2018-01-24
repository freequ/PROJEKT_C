#include <QApplication>
#include "Game.h"
#include "globalscore.h"
#include "garage.h"

Game * game;
Garage * garage;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    GlobalScore gls;
    garage = new Garage(&gls,&a);
    garage->show();

    return a.exec();
}
