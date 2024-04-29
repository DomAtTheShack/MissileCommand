//
// Created by dominichann on 4/28/24.
//

#ifndef MISSILECOMMAND_GAMEOBJECT_H
#define MISSILECOMMAND_GAMEOBJECT_H


#include <SDL.h>

class GameObject {
public:
    GameObject(const char* textureFile, SDL_Renderer* ren);
    ~GameObject();

    void Update();
    void Render();

private:
    int xPos;
    int yPos;
    SDL_Texture *texture;
    SDL_Rect srcRect;
    SDL_Rect destRect;
    SDL_Renderer* renderer;

};


#endif //MISSILECOMMAND_GAMEOBJECT_H
