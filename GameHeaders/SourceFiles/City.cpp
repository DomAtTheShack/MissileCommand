//
// Created by Dominic Hann on 5/6/24.
//

#include "../City.h"
#include "../Game.h"
#include <iostream>


City::City(const char *textureFile, int x, int y) :
        GameObject(textureFile, x, y)
{
    hit = false;
}

City::~City() = default;

void City::Update()
{
    GameObject::Update();
    srcRect.h = 16;
    srcRect.w = 32;
    destRect.x = xPos;
    destRect.y = yPos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
}


int City::getX() const
{
    return xPos;
}

int City::getY() const
{
    return yPos;
}

bool City::isHit()
{
    return hit;
}

void City::Render() {
    GameObject::Render();
}
