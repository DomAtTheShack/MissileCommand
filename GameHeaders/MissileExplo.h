//
// Created by dominichann on 5/20/24.
//

#ifndef MISSILECOMMAND_MISSILEEXPLO_H
#define MISSILECOMMAND_MISSILEEXPLO_H

#define MAX_RADIUS 50

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
    bool next;
    bool retractFlag;
    bool firstShot;
    int radius;
    SDL_Color circleColor;

    SDL_Color RandomColor();
};


#endif //MISSILECOMMAND_MISSILEEXPLO_H
