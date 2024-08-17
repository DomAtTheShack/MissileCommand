//
// Created by dominichann on 5/15/24.
//

#ifndef MISSILECOMMAND_CITY_H
#define MISSILECOMMAND_CITY_H

#include "GameObject.h"

class City : public GameObject{
public:
    City(const char *textureFile, int x, int y, const char *destTextureFile);
    ~City();

    void Render() override;
    void Update() override;

    int getX() const;

    int getY() const;

    bool isHit();

    void explode();

private:
    bool hit;

    SDL_Texture* destCity;
    SDL_Texture * city;
};


#endif //MISSILECOMMAND_CITY_H
