#ifndef GARAGAEDESCRIPTION_H
#define GARAGAEDESCRIPTION_H

#include <QObject>
#include <QGraphicsTextItem>
#include "globalscore.h"

class GarageDescription : public QGraphicsTextItem
{
public:
    GarageDescription(GlobalScore * gls);
    void UpdateDescription();
private:
    GlobalScore * gls;
};

#endif // GARAGAEDESCRIPTION_H
