//
// Created by dominichann on 4/28/24.
//
#include <SDL.h>
#include <cstdio>
#include <vector>

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
    static SDL_Renderer *renderer;
    static Uint16 nextID;
private:
    bool isRunning;
    SDL_Window *window;

};


#endif //PROJECT_NAME_GAME_H
