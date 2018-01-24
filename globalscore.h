#ifndef GLOBALSCORE_H
#define GLOBALSCORE_H

#include <QObject>

class GlobalScore : public QObject
{
    Q_OBJECT
public:
    enum Trait
    {
        HEALTH, TURNACCELARATION, ENEMYSPEED, WEAPONCOOLDOWN
    };
    explicit GlobalScore(QObject *parent = nullptr);
    double globalScore;
    double startCooldown, startTurnAcceleration, startEnemySpeed, startHealth;
    bool TryImprove(Trait trait);
    double GetCost(Trait trait);
signals:

public slots:
private:
    void Improve(Trait trait);
};

#endif // GLOBALSCORE_H
