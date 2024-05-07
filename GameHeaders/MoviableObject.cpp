//
// Created by dominichann on 5/7/24.
//

#include "MoviableObject.h"

MoviableObject::MoviableObject(const char *textureFile, int x, int y) : GameObject(textureFile, x, y)
{
    velX = 0;
    velY = 0;
}

void MoviableObject::Update() {
    GameObject::Update();
    xPos += velX;
    yPos += velY;
}

void MoviableObject::Render() {
    GameObject::Render();
}

MoviableObject::~MoviableObject() = default;
