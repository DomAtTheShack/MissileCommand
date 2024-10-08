//
// Created by dominichann on 4/28/24.
//

#ifndef MISSILECOMMAND_GAMEOBJECT_H
#define MISSILECOMMAND_GAMEOBJECT_H


#include <SDL.h>
#include <vector>
#include <string>

class GameObject {
public:
    GameObject(const char* textureFile, int x, int y);
    virtual ~GameObject();

    virtual void Update();
    virtual void HandleInput(SDL_Event* event);
    virtual void Render();
    virtual std::string getObjectType();

    SDL_Texture *getTexture();

    void setTexture(SDL_Texture *textureToSet);

    bool CheckCollision(GameObject *b) const;

private:
    SDL_Texture *texture;
protected:
    int xPos;
    int yPos;
    SDL_Color color;
    SDL_Rect srcRect;
    SDL_Rect destRect;

};


#endif //MISSILECOMMAND_GAMEOBJECT_H
