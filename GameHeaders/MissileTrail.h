//
// Created by dominichann on 5/11/24.
//

#ifndef MISSILECOMMAND_MISSILETRAIL_H
#define MISSILECOMMAND_MISSILETRAIL_H

#include "MoviableObject.h"


class MissileTrail : public MoviableObject
{
public:
    MissileTrail(const char *textureFile, int x, int y, int vX, int vY);

    ~MissileTrail();

    void Update() override;

    void Render() override;
private:
    int startX;
    int startY;
};


#endif //MISSILECOMMAND_MISSILETRAIL_H
