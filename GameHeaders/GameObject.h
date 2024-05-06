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
    virtual void HandleInput(SDL_Event* event);
    virtual void Render();


protected:
    int xPos;
    int yPos;
private:
    SDL_Texture *texture;
protected:
    SDL_Rect srcRect;
    SDL_Rect destRect;
};


#endif //MISSILECOMMAND_GAMEOBJECT_H
