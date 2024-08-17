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
#include "Missile.h"
#include "MissileExplo.h"

#ifndef GAME_H
#define GAME_H

class PlayerBase;
class Cursor;




#define MISSILE_ID "Missile"
#define GAMEOBJECT_ID "GameObject"

#define DEATH_BY_CITY 1

#define EASY 101
#define MEDIUM 102
#define HARD 103
#define IMMPOSSABLE 104

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

    static void checkMissileCol(MissileExplo* explo);
    static void checkCity(MissileExplo* explo);
    static void checkCity(Missile* explo);

    void checkGameStatus();

    static bool showBoaders;

    short getGameStatus() const;

private:
    bool isRunning;

    void TargetCity(City* cityToHit, int startingX);


    Background* background;
    PlayerBase* playerBase;
    Cursor* cursorG;

    std::vector<City*> cities;

    short missilesLoaded;
    short stacksLeft;

    static std::vector<Missile*> enemyMissiles;

    short gameOver;

    short currentDiffculty;
    short currentRound;
    void startRound();

    bool roundInPlay;

    void checkRoundStart();

    static int randomNumberGen(int a, int b);

};


#endif // GAME_H