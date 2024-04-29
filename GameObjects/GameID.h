//
// Created by dominichann on 4/29/24.
//

#ifndef MISSILECOMMAND_GAMEID_H
#define MISSILECOMMAND_GAMEID_H

#include <SDL_bits.h>

enum ID {
    MISSILE,
    BASE,
    CITY,
    EXPLO,
    PLANE
};
class GameID {

public:
    GameID();
    ~GameID();
    int getObjectID();
private:
    int ObjectID;

};

GameID::GameID() {

}

GameID::~GameID() {

}

int GameID::getObjectID() {
    return 0;
}

#endif //MISSILECOMMAND_GAMEID_H
