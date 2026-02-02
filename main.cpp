#include <SDL.h>
#include <iostream>
#include <set>
#include "GameHeaders/Game.h"
#include "GameHeaders/GameObject.h"
#include "GameHeaders/AudioSystem.h"
#include "GameHeaders/SettingsWindow.h"
#include "GameHeaders/WindowManager.h"




int main(int argc, char* args []) {
    // Game* game = new Game();
    // Game::handler = new Handler();
    Window* window = new SettingsWindow("Settings", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    //game->init("Missile Command", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 700, false);
    //Game::audioSystem->SetVolume(25);
    Uint32 frameStart, frameTime;
    const int FPS = 120;
    const int frameDelay = 1000 / FPS;  // milliseconds per frame
    Uint32 secondStart = SDL_GetTicks();
    int frames = 0;




    while (window->isRunning()) {
        frameStart = SDL_GetTicks();


            window->handleEvents();
            window->update();
            window->render();
            window->getHandler()->toDestroy();
            window = WindowManager::updateWindow(window);


        frames++;

        if (SDL_GetTicks() - secondStart >= 1000) {
            std::cout << "FPS: " << frames << std::endl;
            frames = 0;
            secondStart = SDL_GetTicks();
            //game->testLaunch();
        }

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    window->clean();
    delete window;
    SDL_Quit();

    return 0;
}
