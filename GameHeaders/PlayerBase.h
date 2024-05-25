//
// Created by Dominic Hann on 5/6/24.
//

#ifndef MISSILECOMMAND_PLAYERBASE_H
#define MISSILECOMMAND_PLAYERBASE_H


#include "GameObject.h"
#include "Cursor.h"
#include "Game.h"

#define PLAYERBASE_X 585
#define PLAYERBASE_Y 520
#define BASE_X 590 // Starting x-coordinate for the pyramid
#define BASE_Y 575 // Starting y-coordinate for the pyramid
#define SQUARE_W 10
#define SQUARE_H 8
#define SPACING 10 // Space between squares

class Cursor; // Forward declaration

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
    int missiles;
    bool isHit();
    Game& currentGame;
    void RenderMissiles();
};


#endif //MISSILECOMMAND_PLAYERBASE_H
