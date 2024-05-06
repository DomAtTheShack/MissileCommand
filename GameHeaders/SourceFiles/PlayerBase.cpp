//
// Created by Dominic Hann on 5/6/24.
//

#include "../PlayerBase.h"
#include "../Cursor.h"
#include <iostream>

PlayerBase::PlayerBase(const char *textureFile, int x, int y, Cursor* cursor) :
            GameObject(textureFile, x, y)
{
    this->cursorInPlay = cursor;
}

PlayerBase::~PlayerBase() = default;

void PlayerBase::Render()
{
    GameObject::Render();
    cursorInPlay->Render();
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

void PlayerBase::fire()
{

}

bool PlayerBase::isHit()
{
    return false;
}
