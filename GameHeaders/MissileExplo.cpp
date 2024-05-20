//
// Created by dominichann on 5/20/24.
//

#include "MissileExplo.h"
#include "Game.h"

MissileExplo::MissileExplo(const char *textureFile, int x, int y) : GameObject(textureFile, x, y)
{
    radius = 50;
    circleColor = {255, 0, 0, 255};
}

MissileExplo::~MissileExplo() = default;

void MissileExplo::Update()
{
    GameObject::Update();

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
