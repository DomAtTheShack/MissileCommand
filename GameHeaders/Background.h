#ifndef MISSILE_COMMAND_BACKGROUND_H
#define MISSILE_COMMAND_BACKGROUND_H

#include <SDL2/SDL.h>

class Background {
public:
    Background(const char* texture);
    ~Background();

    void Update();
    void Render();

private:
    SDL_Texture* texture = nullptr;
    SDL_Rect sdlRect;
    const int speed = 5; // Modify the speed value to your liking
    int xPos = 0;
    int yPos = 0;
};

#endif