//
// Created by dominichann on 5/20/24.
//

#ifndef MISSILECOMMAND_MISSILEEXPLO_H
#define MISSILECOMMAND_MISSILEEXPLO_H


#include "GameObject.h"

class MissileExplo : public GameObject
{
public:
    MissileExplo(const char *textureFile, int x, int y);
    ~MissileExplo();

    void Update() override;
    void Render() override;

private:
    short exploTimer;
    int radius;
    SDL_Color circleColor;

};


#endif //MISSILECOMMAND_MISSILEEXPLO_H
