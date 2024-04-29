//
// Created by dominichann on 4/28/24.
//
#include <SDL.h>
#include <cstdio>

#ifndef PROJECT_NAME_GAME_H
#define PROJECT_NAME_GAME_H


class Game {

public:
    Game();
    ~Game();

    void init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() const;

private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;

};


#endif //PROJECT_NAME_GAME_H
