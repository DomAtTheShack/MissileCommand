//
// Created by dominichann on 4/28/24.
//
#include <SDL.h>
#include <cstdio>
#include <vector>
#include "Handler.h"

#ifndef PROJECT_NAME_GAME_H
#define PROJECT_NAME_GAME_H


class Game {

public:
    Game(Handler *handler);
    ~Game();

    void init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() const;
    static SDL_Renderer *renderer;
    static SDL_Window *window;

    static int nextID;

    void addObject(GameObject &object);

    void removeObject(GameObject &object);
private:
    bool isRunning;
    Handler *handler;

};


#endif //PROJECT_NAME_GAME_H
