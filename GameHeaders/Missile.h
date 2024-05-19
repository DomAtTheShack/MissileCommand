//
// Created by dominichann on 5/12/24.
//

#ifndef MISSILECOMMAND_MISSILE_H
#define MISSILECOMMAND_MISSILE_H


#include "MoviableObject.h"
#include "MissileTrail.h"

class Missile : public MoviableObject
{
public:
    Missile(const char *textureFile, int x, int y, int vX, int vY, int kpX, int kpY);

    ~Missile();

       void Update() override;
       void Render() override;

       void createTrail();
private:
    MissileTrail* Trail;
    void TargetBase();
    int killPointX;
    int killPointY;

    bool willPassKillPoint(int nextX, int nextY);
};


#endif //MISSILECOMMAND_MISSILE_H
