//
// Created by Dominic Hann on 5/6/24.
//

#include "../Cursor.h"

Cursor::Cursor(const char *textureFile, int x, int y) : GameObject(textureFile, x, y)
{
    xPos = x;
    yPos = y;
    velY = 0;
    velX = 0;
    fired = false;
}

Cursor::~Cursor() = default;

void Cursor::Update() {
    GameObject::Update();
    xPos += velX;
    yPos += velY;

    // Screen boundaries (assumed screen size: 1280x720)
    const int screenWidth = 1200;
    const int screenHeight = 550;

    // Adjust if out of bounds
    if (xPos < 0) xPos = 0;
    if (xPos > screenWidth - srcRect.w * 2) xPos = screenWidth - srcRect.w * 2;
    if (yPos < 0) yPos = 0;
    if (yPos > screenHeight - srcRect.h * 2) yPos = screenHeight - srcRect.h * 2;

    srcRect.h = 12;
    srcRect.w = 12;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
}

void Cursor::Render() {
    GameObject::Render();
}

void Cursor::HandleInput(SDL_Event *event)
{
    if (event->type == SDL_KEYDOWN)
    {
        switch (event->key.keysym.sym)
        {
            case SDLK_UP:
                velY = -3;
                break;
            case SDLK_DOWN:
                velY = 3;
                break;
            case SDLK_LEFT:
                velX = -3;
                break;
            case SDLK_RIGHT:
                velX = 3;
                break;
            default:
                break;
        }
    }
    if (event->type == SDL_KEYUP)
    {
        switch (event->key.keysym.sym)
        {
            case SDLK_UP:
            case SDLK_DOWN:
                velY = 0;
                break;
            case SDLK_LEFT:
            case SDLK_RIGHT:
                velX = 0;
                break;
            case SDLK_SPACE:
                fired = false;
                break;
            default:
                break;
        }
    }
}

int Cursor::getX() const {
    return xPos;
}

int Cursor::getY() const {
    return yPos;
}
