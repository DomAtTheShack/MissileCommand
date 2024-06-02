//
// Created by dominichann on 5/12/24.
//

#ifndef MISSILECOMMAND_MISSILE_H
#define MISSILECOMMAND_MISSILE_H


#include "MoviableObject.h"
#include "MissileTrail.h"

class Missile : public MoviableObject {
public:
    Missile(const char *textureFile, float x, float y, float vX, float vY, float kpX, float kpY, bool baseMissile);
    ~Missile();

    void Update() override;
    void Render() override;
    std::string getObjectType() override;

private:
    float killPointX, killPointY;
    MissileTrail* Trail;
    bool baseMiss;

    void createTrail();
    void TargetBase();

    SDL_Color color;

    static std::pair<std::string, std::string> missileSFX;
    static bool madeSFX;
};

#endif //MISSILECOMMAND_MISSILE_H
