//
// Created by dominichann on 5/7/24.
//

#include "../MoviableObject.h"

MoviableObject::MoviableObject(const char *textureFile, int x, int y, int vX, int vY) : GameObject(textureFile, x, y)
{
    velX = vX;
    velY = vY;
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
