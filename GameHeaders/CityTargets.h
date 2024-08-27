//
// Created by dominichann on 8/24/24.
//

#ifndef MISSILECOMMAND_CITYTARGETS_H
#define MISSILECOMMAND_CITYTARGETS_H

struct CityTarget {
    int velX;
    int velY;
    int startingX;
    int killPointModX;
    int killPointModY;
};

CityTarget cities[6][3] = {
        // CITY_1A, CITY_1B, CITY_1C
        {{-3, 3, 600, 0, 0}, {0, 3, 80, 0, 0}, {-6, 3, 1150, 0, 10}},
        // CITY_2A, CITY_2B, CITY_2C
        {{-2, 3, 600, 0, 0}, {0, 3, 220, 0, 0}, {-5, 3, 1150, 0, 10}},
        // CITY_3A, CITY_3B, CITY_3C
        {{2, 3, 40, 15, 25}, {0, 3, 405, 0, 0}, {-4, 3, 1150, 0, 10}},
        // CITY_4A, CITY_4B, CITY_4C
        {{4, 3, 20, 50, 55}, {1, 3, 585, 0, 0}, {-2, 3, 1150, 0, 10}},
        // CITY_5A, CITY_5B, CITY_5C
        {{5, 3, 20, 30, 55}, {1, 3, 765, 60, 0}, {-1, 3, 1150, 0, 10}},
        // CITY_6A, CITY_6B, CITY_6C
        {{6, 3, 20, 30, 55}, {3, 3, 580, 0, 0}, {0, 2, 1120, 0, 10}}
};

CityTarget getCity(int cityNum, int attackVariation)
{
    if(cityNum >= 6 || attackVariation >= 3)
        return {1,1,0,0,0}; // Bad City
    return cities[cityNum][attackVariation];
}


#endif //MISSILECOMMAND_CITYTARGETS_H
