#include "gun.h"
#include "bullet.h"
#include "game.h"
#include <functional>

Gun::Gun(Player * player)
{
    timer = new QTimer();
    cooldown = player->game->gls->startCooldown;
    isOnCooldown = cooldown == 5000;
    this ->player = player;
    //connect(timer, SIGNAL(timeout()), this, SLOT(take_down_cooldown())
}

void Gun::try_shoot()
{
    if(!isOnCooldown)
    {
        Bullet * bullet = new Bullet(player->game);
        bullet->setPos(player->pos().x()+player->rect().width()/2,player->pos().y());
        player->game->scene->addItem(bullet);
        isOnCooldown = true;
        timer->singleShot(cooldown,this,SLOT(take_down_cooldown()));
    }
}

void Gun::take_down_cooldown()
{
    isOnCooldown = false;
}
