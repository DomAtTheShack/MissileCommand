//
// Created by dominichann on 4/28/24.
//

#ifndef MISSILECOMMAND_GAMEOBJECT_H
#define MISSILECOMMAND_GAMEOBJECT_H


#include <SDL.h>
#include <vector>

class GameObject {
public:
    GameObject(const char* textureFile, int x, int y);
    ~GameObject();

    virtual void Update();

    virtual void Render();


private:
    int xPos;
    int yPos;
    SDL_Texture *texture;
    SDL_Rect srcRect;
    SDL_Rect destRect;
    std::vector<GameObject> GameObjects;
};


#endif //MISSILECOMMAND_GAMEOBJECT_H
