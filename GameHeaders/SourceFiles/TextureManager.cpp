#include "../TextureManager.h"
#include <SDL_image.h>
#include <SDL.h>
#include <iostream>

SDL_Texture *TextureManager::LoadTexture(const char *fileName)
{
    if(fileName != nullptr) {
        SDL_Surface *tempSurface = IMG_Load(fileName);
        if (!tempSurface) {
            std::cerr << "Failed to load image " << fileName << ". SDL_image Error: " << IMG_GetError() << std::endl;
            return nullptr;
        }

        SDL_Texture *texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
        if (!texture) {
            std::cerr << "Unable to create texture from " << fileName << ". SDL Error: " << SDL_GetError() << std::endl;
        }

        SDL_FreeSurface(tempSurface);
        return texture;
    }else{
        return nullptr;
    }
}
SDL_Texture* TextureManager::LoadBMP(const char* textureFile) {
    SDL_Surface* tempSurface = SDL_LoadBMP(textureFile);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return texture;
}