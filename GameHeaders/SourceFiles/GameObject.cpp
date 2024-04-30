//
// Created by dominichann on 4/28/24.
//

#include "../GameObject.h"
#include "../TextureManager.h"

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
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);
}


