//
// Created by Dominic Hann on 5/6/24.
//

#ifndef MISSILECOMMAND_PLAYERBASE_H
#define MISSILECOMMAND_PLAYERBASE_H


#include "GameObject.h"
#include "PlayerBase.h"
#include "Cursor.h"

class Cursor; // Forward declaration
#define PLAYERBASE_X 585
#define PLAYERBASE_Y 520

class PlayerBase : public GameObject
{
public:
    PlayerBase(const char *textureFile, int x, int y, Cursor* cursor);
    ~PlayerBase();


    void Render() override;
    void Update() override;

    void fire(int x, int y);
    bool isHit();

private:
    Cursor* cursorInPlay;
    bool fired;

    void HandleInput(SDL_Event *event);
};


#endif //MISSILECOMMAND_PLAYERBASE_H
