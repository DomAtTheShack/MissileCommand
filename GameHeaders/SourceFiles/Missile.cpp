//
// Created by dominichann on 5/12/24.
//

#include "../Missile.h"
#include "../Game.h"
#include <cmath> // For abs function

Missile::Missile(const char *textureFile, int x, int y, int vX, int vY, int kpX, int kpY)
        : MoviableObject(textureFile, x, y, vX, vY), killPointX(kpX), killPointY(kpY), Trail(nullptr) {
    createTrail();
}

Missile::~Missile() = default;

void Missile::Update() {
    // Check if the missile has reached the kill point
    if (std::abs(xPos) <= std::abs(killPointX) && std::abs(yPos) <= std::abs(killPointY)) {
        Game::handler->removeObject(Trail);
        Game::handler->removeObject(this);
    }

    MoviableObject::Update();
}

void Missile::Render() {
    SDL_Rect square = {xPos, yPos, 10, 8};
    SDL_RenderFillRect(Game::renderer, &square);
}

void Missile::createTrail() {
    Trail = new MissileTrail(nullptr, xPos - 10, yPos - 10, velX, velY);
    Game::handler->addObject(Trail);
}

void Missile::TargetBase() {
    // Optional: Implement targeting logic if needed
}
