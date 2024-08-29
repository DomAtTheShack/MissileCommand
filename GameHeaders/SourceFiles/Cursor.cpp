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
    cursSpeed = DEFAULT_CUR_SPEED;
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
            if(event->key.keysym.sym == SDLK_UP)
                velY = -DEFAULT_CUR_SPEED;
            if(event->key.keysym.sym == SDLK_DOWN)
                velY = DEFAULT_CUR_SPEED;
            if(event->key.keysym.sym == SDLK_RIGHT)
                velX = DEFAULT_CUR_SPEED;
            if(event->key.keysym.sym == SDLK_LEFT)
                velX = -DEFAULT_CUR_SPEED;
            if(event->key.keysym.sym == SDLK_SPACE)
                fired = false;
    }
    if (event->type == SDL_KEYUP)
    {
        if(event->key.keysym.sym == SDLK_UP ||
            event->key.keysym.sym == SDLK_DOWN)
            velY = 0;
        if(event->key.keysym.sym == SDLK_RIGHT ||
                event->key.keysym.sym == SDLK_LEFT)
            velX = 0;
        if(event->key.keysym.sym == SDLK_SPACE)
            fired = false;
    }
}

int Cursor::getX() const {
    return xPos;
}

int Cursor::getY() const {
    return yPos;
}
