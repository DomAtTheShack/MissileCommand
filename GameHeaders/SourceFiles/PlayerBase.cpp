//
// Created by Dominic Hann on 5/6/24.
//

#include "../PlayerBase.h"
#include "../Cursor.h"
#include "../Game.h"
#include "../MissileTrail.h"
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
    Game::handler->addObject(new MissileTrail(nullptr, cursorInPlay->getX(),cursorInPlay->getY(), -2, 1));

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
