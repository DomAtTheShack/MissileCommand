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

class PlayerBase : public GameObject {
public:
    PlayerBase(const char *textureFile, float x, float y, Cursor* cursor);
    ~PlayerBase();

    void Update() override;
    void Render() override;
    void HandleInput(SDL_Event *event) override;
    void fire(float x, float y); // Updated to use float

private:
    Cursor* cursorInPlay;
    bool fired;
    static int gcd(int a, int b);

    bool isHit();
};


#endif //MISSILECOMMAND_PLAYERBASE_H
