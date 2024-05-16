//
// Created by dominichann on 4/28/24.
//

#include "Game.h"
#include <SDL_image.h>


#ifndef PROJECT_NAME_TEXTUREMANAGER_H
#define PROJECT_NAME_TEXTUREMANAGER_H



class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* fileName);

    static SDL_Texture *LoadBMP(const char *textureFile);
};


#endif //PROJECT_NAME_TEXTUREMANAGER_H
