//
// Created by dominichann on 5/11/24.
//

#include "../MissileTrail.h"
#include "../Game.h"

MissileTrail::MissileTrail(const char *textureFile, int x, int y, int vX, int vY)
        : MoviableObject(textureFile, x, y, vX, vY) {
    startX = x;
    startY = y;
    xPos = x;
    yPos = y;
}

void MissileTrail::Update() {
    MoviableObject::Update();
}

void MissileTrail::Render()
{
        SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, SDL_ALPHA_OPAQUE); // Set color to black
        for (int offset = -10; offset <= 10; ++offset) {
            SDL_RenderDrawLine(Game::renderer, xPos + offset, yPos + offset, startX + offset,
                               startY + offset);
        }
}

MissileTrail::~MissileTrail() = default;
