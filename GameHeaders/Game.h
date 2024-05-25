//
// Created by dominichann on 4/28/24.
//
#include <SDL.h>
#include <iostream>
#include <vector>
#include "Handler.h"
#include "Background.h"
#include "City.h"
#include "AudioSystem.h"
#include "Cursor.h"

class PlayerBase;
class Cursor;

#ifndef PROJECT_NAME_GAME_H
#define PROJECT_NAME_GAME_H


class Game {

public:
    Game();
    ~Game();

    static Game& getInstance() {
        static Game instance;
        return instance;
    }

    void init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    void endGame();

    bool running() const;
    static SDL_Renderer *renderer;
    static SDL_Window *window;

    static int nextID;

    static Handler *handler;
    static AudioSystem* audioSystem;

    void missileShot();
    void reload();
    bool checkMissile(short x) const;
    short missilesLeft() const;

private:
    bool isRunning;

    Background* background;
    PlayerBase* playerBase;
    Cursor* cursorG;

    std::vector<City*> cities;

    short missilesLoaded;
    short stacksLeft;
};


#endif //PROJECT_NAME_GAME_H
