//
// Created by dominichann on 4/28/24.
//

#include "../GameObject.h"
#include "../TextureManager.h"
#include "../Window.h"
#include <iostream>

GameObject::GameObject(const char *textureFile, int x, int y) {
    texture = TextureManager::LoadTexture(textureFile);

    xPos = x;
    yPos = y;

    // 1. Initialize to 0 just in case
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = 0;
    srcRect.h = 0;

    // 2. Automatically get the width (w) and height (h) of the loaded image
    if (texture != nullptr) {
        SDL_QueryTexture(texture, NULL, NULL, &srcRect.w, &srcRect.h);
    } else {
        // Fallback if load failed
        srcRect.w = 32;
        srcRect.h = 32;
    }

    // 3. Set the Destination (Where it goes on screen)
    destRect.x = xPos;
    destRect.y = yPos;

    // Maintain your 2x scale logic
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
}

GameObject::~GameObject() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}

void GameObject::Update() {
    destRect.x = xPos;
    destRect.y = yPos;
}

void GameObject::Render() {
    if(texture != nullptr)
        SDL_RenderCopy(Window::renderer, texture, &srcRect, &destRect);
    if(Window::showingBoarders()) {
        // SAVE the old color (Optional but good practice)
        Uint8 r, g, b, a;
        SDL_GetRenderDrawColor(Window::renderer, &r, &g, &b, &a);

        // SET new color to Bright Red (Red, Green, Blue, Alpha)
        SDL_SetRenderDrawColor(Window::renderer, 255, 0, 0, 255);

        // DRAW the rectangle
        SDL_RenderDrawRect(Window::renderer, &destRect);

        // RESTORE the old color (so you don't mess up the next clear/draw)
        SDL_SetRenderDrawColor(Window::renderer, r, g, b, a);
    }
}

void GameObject::HandleInput(SDL_Event *event) {}

bool GameObject::CheckCollision(GameObject* b) const {
    if(destRect.x < b->destRect.x + b->destRect.w &&
            destRect.x + destRect.w > b->destRect.x &&
            destRect.y < b->destRect.y + b->destRect.h &&
            destRect.y + destRect.h > b->destRect.y)
    {
        return true;
    }
        return false;
}

std::string GameObject::getObjectType()
{
    return "GameObject";
}

SDL_Texture* GameObject::getTexture() {
    return texture;
}

void GameObject::setTexture(SDL_Texture* textureToSet) {
    texture = textureToSet;
}


