//
// Created by dominichann on 5/20/24.
//

#include <random>
#include "../MissileExplo.h"
#include "../Game.h"

MissileExplo::MissileExplo(const char *textureFile, int x, int y) : GameObject(textureFile, x, y)
{
    radius = 5;
    circleColor = RandomColor();
    exploTimer = 0;
    next = false;
    retractFlag = false;
    firstShot = true;
}

MissileExplo::~MissileExplo() = default;

void MissileExplo::Update()
{
    if(retractFlag)
    {
        if (next) {
            radius--;
            next = false;
            circleColor = RandomColor();
            if (radius == 0)
                Game::handler->removeObject(this);
        } else {
            exploTimer++;
        }
        if (exploTimer >= 15)
            next = true;
    } else {
        if (next || firstShot) {
            radius++;
            firstShot = false;
            next = false;
            circleColor = RandomColor();
            if (radius == MAX_RADIUS)
                retractFlag = true;
        } else {
            exploTimer++;
        }
        if (exploTimer >= 10)
            next = true;
    }
    Missile* tempM = Game::checkMissileCol(this);
    if(tempM != nullptr)
        {
            Game::handler->removeObject(tempM);
        }
}

void MissileExplo::Render()
{
    GameObject::Render();

    SDL_SetRenderDrawColor(Game::renderer, circleColor.r, circleColor.g, circleColor.b, circleColor.a);
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx*dx + dy*dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(Game::renderer, xPos + dx, yPos + dy);
            }
        }
    }
}
SDL_Color MissileExplo::RandomColor()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);

    return {static_cast<Uint8>(dis(gen)),static_cast<Uint8>(dis(gen)),static_cast<Uint8>(dis(gen)),static_cast<Uint8>(dis(gen))};
}
