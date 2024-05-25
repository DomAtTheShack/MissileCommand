#include <SDL.h>
#include <iostream>
#include "GameHeaders/Game.h"
#include "GameHeaders/TextureManager.h"
#include "GameHeaders/GameObject.h"
#include "GameHeaders/Handler.h"
#include "GameHeaders/AudioSystem.h"
#include <random>

Game* game = nullptr;

int main(int argc, char* args []) {
    game = new Game();
    Game::handler = new Handler();

    game->init("Missile Command", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 700, false);
    Game::audioSystem->SetVolume(25);
    Uint32 frameStart, frameTime;
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;  // milliseconds per frame
    Uint32 secondStart = SDL_GetTicks();
    int frames = 0;

    auto *player = new GameObject("assets/images/player.png", 100, 100);
    Game::handler->addObject(player);


    while (game->running()) {
        frameStart = SDL_GetTicks();



        game->handleEvents();
        game->update();
        game->render();
        Game::handler->toDestroy();



        frames++;

        if (SDL_GetTicks() - secondStart >= 1000) {
            std::cout << "FPS: " << frames << std::endl;
            frames = 0;
            secondStart = SDL_GetTicks();
        }

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();

    return 0;
}
