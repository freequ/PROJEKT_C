#include "globalscore.h"

GlobalScore::GlobalScore(QObject *parent) : QObject(parent)
{
    globalScore = 0;
    startCooldown = 5000;
    startEnemySpeed = 1.500;
    startTurnAcceleration = 0.003;
    startHealth = 1;
}

bool GlobalScore::TryImprove(GlobalScore::Trait trait)
{
    double cost = GetCost(trait);
    if(cost <= globalScore)
    {
        globalScore -= cost;
        Improve(trait);
        return true;
    }
    return false;
}

double GlobalScore::GetCost(GlobalScore::Trait trait)
{
    return 1;
}

void GlobalScore::Improve(GlobalScore::Trait trait)
{
    switch (trait) {
    case Trait::HEALTH:
        startHealth++;
        break;
    case Trait::TURNACCELARATION:
        startTurnAcceleration+=0.1;
        break;
    case Trait::ENEMYSPEED:
        startEnemySpeed-=startEnemySpeed/50;
        break;
    case Trait::WEAPONCOOLDOWN:
        startCooldown-=startCooldown/15;
        break;
    }
}
