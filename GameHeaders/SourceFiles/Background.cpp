#include <iostream>
#include "../Background.h"
#include "../Game.h"
#include "../TextureManager.h"

Background::Background(const char *textureFile) {
    texture = TextureManager::LoadBMP(textureFile);
    if (texture == nullptr) {
        SDL_ShowSimpleMessageBox(0, "Texture init error", SDL_GetError(), nullptr);
    }
    xPos = 0;
    yPos = 0;
    sdlRect.x = xPos;
    sdlRect.y = yPos;
    sdlRect.w = 1200; // Replace these with your values
    sdlRect.h = 700; // Replace these with your values
}

Background::~Background() {
    SDL_DestroyTexture(texture);
}

void Background::Update(){
    // Example of how to make your background move downwards over time
    yPos += speed;
    sdlRect.y += speed;
    if (sdlRect.y > 1200 - 1200) {
        sdlRect.y = 0;
    }
}

void Background::Render() {
    SDL_RenderCopy(Game::renderer, texture, nullptr, &sdlRect);
}