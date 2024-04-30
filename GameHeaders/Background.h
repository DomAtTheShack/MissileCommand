//
// Created by dominichann on 4/29/24.
//

#ifndef MISSILECOMMAND_BACKGROUND_H
#define MISSILECOMMAND_BACKGROUND_H


#include <SDL.h>
#include "GameObject.h"

class Background : public GameObject {
public:
    Background(const char *textureSheet);

    ~Background();

    void Update() override;

    void Render() override;

private:
    int xPos, yPos;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;
};


#endif //MISSILECOMMAND_BACKGROUND_H
