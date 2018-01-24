#include "garagedescription.h"
#include <QFont>

GarageDescription::GarageDescription(GlobalScore * gls)
{
    this->gls = gls;
    UpdateDescription();
}

void GarageDescription::UpdateDescription()
{
    setPlainText(QString("\n\n                                      ") + QString::number(gls->globalScore)+QString(" \n                                                                      \n                                              ") + QString::number(gls->GetCost(gls->Trait::HEALTH)) +
                                                                              QString("\n                                              ") + QString::number(gls->GetCost(gls->Trait::TURNACCELARATION)) +
                                                                              QString("\n                                              ") + QString::number(gls->GetCost(gls->Trait::ENEMYSPEED)) +
                                                                              QString("\n                                              ") + QString::number(gls->GetCost(gls->Trait::WEAPONCOOLDOWN)));




    setDefaultTextColor(Qt::black);
    setFont(QFont("Arial",30));
}



