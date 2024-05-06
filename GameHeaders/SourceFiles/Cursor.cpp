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
}

Cursor::~Cursor() = default;

void Cursor::Update() {
    GameObject::Update();
    xPos += velX;
    yPos += velY;
}

void Cursor::Render() {
    GameObject::Render();
}

int Cursor::getX() const {
    return xPos;
}

int Cursor::getY() const {
    return yPos;
}

void Cursor::HandleInput(SDL_Event *event)
{
    if (event->type == SDL_KEYDOWN)
    {
        switch (event->key.keysym.sym)
        {
            case SDLK_UP:
                velY = -5;
                break;
            case SDLK_DOWN:
                velY = 5;
                break;
            case SDLK_LEFT:
                velX = -5;
                break;
            case SDLK_RIGHT:
                velX = 5;
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
            default:
                break;
        }
    }
}
