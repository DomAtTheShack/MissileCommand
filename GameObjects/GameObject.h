//
// Created by dominichann on 4/28/24.
//

#ifndef MISSILECOMMAND_GAMEOBJECT_H
#define MISSILECOMMAND_GAMEOBJECT_H


#include <SDL.h>

class GameObject {
public:
    GameObject(const char* textureFile, int x, int y);
    ~GameObject();

    void Update();
    void Render();

private:
    int xPos;
    int yPos;
    SDL_Texture *texture;
    SDL_Rect srcRect;
    SDL_Rect destRect;
};


#endif //MISSILECOMMAND_GAMEOBJECT_H
