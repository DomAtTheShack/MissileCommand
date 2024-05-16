//
// Created by dominichann on 5/15/24.
//

#ifndef MISSILECOMMAND_CITY_H
#define MISSILECOMMAND_CITY_H

#include "GameObject.h"

class City : public GameObject{
public:
    City(const char *textureFile, int x, int y);
    ~City();

    void Render() override;
    void Update() override;

    bool isHit();

private:
    bool hit;

};


#endif //MISSILECOMMAND_CITY_H
