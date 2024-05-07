//
// Created by Dominic Hann on 5/6/24.
//

#include "../PlayerBase.h"
#include "../Cursor.h"
#include "../Game.h"
#include <iostream>

class PlayerBase; // Forward declaration

PlayerBase::PlayerBase(const char *textureFile, int x, int y, Cursor* cursor) :
            GameObject(textureFile, x, y)
{
    this->cursorInPlay = cursor;
    fired = false;
}

PlayerBase::~PlayerBase() = default;

void PlayerBase::Render()
{
    GameObject::Render();
    cursorInPlay->Render();
    if(fired) {
        int x1 = cursorInPlay->getX() + 16; // X coordinate of the start point
        int y1 = cursorInPlay->getY() + 16; // Y coordinate of the start point
        int x2 = xPos + 32; // X coordinate of the end point
        int y2 = yPos + 32; // Y coordinate of the end point
        SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, SDL_ALPHA_OPAQUE); // Set color to black
        for (int offset = -2; offset <= 2; ++offset) {
            SDL_RenderDrawLine(Game::renderer, x1, y1 + offset, x2, y2 + offset); // Only offset Y values
        }

        SDL_RenderPresent(Game::renderer);
    }
}

void PlayerBase::Update()
{
    GameObject::Update();
    srcRect.h = 64;
    srcRect.w = 64;
    destRect.x = xPos;
    destRect.y = yPos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
    cursorInPlay->Update();
}

void PlayerBase::fire(int x, int y)
{
    // Assume you already have SDL initialized and an SDL_Renderer* named renderer



}

bool PlayerBase::isHit()
{
    return false;
}
void PlayerBase::HandleInput(SDL_Event *event)
{
    if (event->type == SDL_KEYDOWN)
    {
        switch (event->key.keysym.sym)
        {
            case SDLK_SPACE:
                if(!fired)
                {
                    fired = true;
                    fire(cursorInPlay->getX(), cursorInPlay->getY());
                }
            default:
                break;
        }
    }
    if (event->type == SDL_KEYUP)
    {
        switch (event->key.keysym.sym)
        {
            case SDLK_SPACE:
                fired = false;
                break;
            default:
                break;
        }
    }
}
