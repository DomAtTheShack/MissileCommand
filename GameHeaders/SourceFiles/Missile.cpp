#include "../Missile.h"
#include "../Game.h"
#include <cmath>

Missile::Missile(const char *textureFile, float x, float y, float vX, float vY, float kpX, float kpY, bool baseMissile)
        : MoviableObject(textureFile, x, y, vX, vY), killPointX(kpX), killPointY(kpY), Trail(nullptr)
        {
    if(!baseMissile)
        createTrail();
    baseMiss = baseMissile;
}

Missile::~Missile() = default;

void Missile::Update() {
    // Check if the missile has reached or passed the kill point
    if ((velX > 0 && xPos >= killPointX) || (velX < 0 && xPos <= killPointX) ||
        (velY > 0 && yPos >= killPointY) || (velY < 0 && yPos <= killPointY)) {
        if(!baseMiss)
            Game::handler->removeObject(Trail);
        Game::handler->removeObject(this);
        return; // Exit the update function to prevent further updates
    }

    MoviableObject::Update();
}

void Missile::Render() {
    SDL_Rect square = {static_cast<int>(xPos), static_cast<int>(yPos), 10, 8};
    SDL_RenderFillRect(Game::renderer, &square);
}

void Missile::createTrail() {
    Trail = new MissileTrail(nullptr, xPos - 10, yPos - 10, velX, velY);
    Game::handler->addObject(Trail);
}

void Missile::TargetBase() {
    // Optional: Implement targeting logic if needed
}
