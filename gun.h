#ifndef GUN_H
#define GUN_H

#include <QObject>
#include <QTimer>
#include "player.h"

class Gun : public QObject
{
    Q_OBJECT
public:
    Gun(Player * player);
    void try_shoot();
public slots:
    void take_down_cooldown();
private:
    double cooldown;
    QTimer * timer;
    bool isOnCooldown;
    Player * player;
};

#endif // GUN_H
