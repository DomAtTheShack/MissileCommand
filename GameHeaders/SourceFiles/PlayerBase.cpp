//
// Created by Dominic Hann on 5/6/24.
//

#include "../PlayerBase.h"
#include "../Cursor.h"
#include "../Game.h"
#include "../MissileTrail.h"
#include "../Missile.h"
#include <iostream>
#include <cmath> // For sqrt function


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
    srcRect.x = xPos;
    srcRect.h = yPos;
    srcRect.h = 2;
    srcRect.w = 5;
    destRect.x = xPos + 5;
    destRect.y = yPos + 5;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
    cursorInPlay->Update();
}


void PlayerBase::fire(int x, int y)
{
    if (Game::handler != nullptr && cursorInPlay != nullptr) {
        // Calculate the velocity vector components
        int vX = x - xPos; // Calculate the difference between cursor x and player base x
        int vY = y - yPos; // Calculate the difference between cursor y and player base y

        // Calculate the length of the vector
        float length = sqrt(vX * vX + vY * vY);

        // Prevent division by zero in case the length is zero
        if (length == 0) {
            length = 1;
        }

        // Normalize the vector
        float normVX = vX / length;
        float normVY = vY / length;

        // Define the desired speed
        float speed = 6.0f;

        // Scale the normalized vector to the desired speed
        int scaledVX = normVX * speed;
        int scaledVY = normVY * speed;

        // Create and add the missile object with the scaled velocities
        Game::handler->addObject(new Missile(nullptr, xPos, yPos, scaledVX, scaledVY, x, y));
    }
}




bool PlayerBase::isHit()
{
    return false;
}

void PlayerBase::HandleInput(SDL_Event* event)
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
