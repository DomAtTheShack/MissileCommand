//
// Created by dominichann on 4/28/24.
//

#include "../GameObject.h"
#include "../TextureManager.h"
#include <iostream>

GameObject::GameObject(const char *textureFile, int x, int y) {
    texture = TextureManager::LoadTexture(textureFile);

    xPos = x;
    yPos = y;
}

GameObject::~GameObject() = default;

void GameObject::Update() {
    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xPos;
    destRect.y = yPos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
}

void GameObject::Render() {
    if(texture != nullptr)
        SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);
    if(Game::showBoaders)
        SDL_RenderDrawRect(Game::renderer, &destRect);
}

void GameObject::HandleInput(SDL_Event *event) {}

bool GameObject::CheckCollision(GameObject* b) const {
    if(destRect.x < b->destRect.x + b->destRect.w &&
            destRect.x + destRect.w > b->destRect.x &&
            destRect.y < b->destRect.y + b->destRect.h &&
            destRect.y + destRect.h > b->destRect.y)
    {
        std::cout << "HIT" << '\n';
        return true;
    }else
        return false;
}

std::string GameObject::getObjectType()
{
    return "GameObject";
}


