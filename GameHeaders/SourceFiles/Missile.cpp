//
// Created by dominichann on 5/12/24.
//

#include "../Missile.h"
#include "../Game.h"

Missile::Missile(const char *textureFile, int x, int y, int vX, int vY) : MoviableObject(textureFile, x, y, vX, vY) {
    Trail = nullptr;
    TargetBase();
    createTrail();
}

Missile::~Missile() = default;

void Missile::Update() {
    MoviableObject::Update();
}

void Missile::Render()
{
    SDL_Rect square = {xPos,yPos,10,8};
    SDL_RenderFillRect(Game::renderer, &square);
    if(yPos > 600)
    {
        Game::handler->removeObject(Trail);
        Game::handler->removeObject(this);
    }
}

void Missile::createTrail() {
    Trail = new MissileTrail(nullptr, xPos - 10, yPos - 10, velX, velY);
    Game::handler->addObject(Trail);
}

void Missile::TargetBase() {

}
