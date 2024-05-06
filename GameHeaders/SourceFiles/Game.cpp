//
// Created by dominichann on 4/28/24.
//

#include <iostream>
#include "../Game.h"
#include "../TextureManager.h"

int Game::nextID = 0;

Game::Game(Handler *hand) {
    handler = hand;
    background = nullptr;
    playerBase = nullptr;
    cursorG = nullptr;
}

Game::~Game() = default;

SDL_Renderer* Game::renderer = nullptr;
SDL_Window *Game::window = nullptr;

void Game::init(const char *title, int xPos, int yPos, int width, int height, bool fullscreen) {
    isRunning = false;
    if((SDL_Init(SDL_INIT_EVERYTHING)) == 0) {
        SDL_Log("SubSystem Initialing");


        int flags = 0;
        if (fullscreen)
            flags = SDL_WINDOW_FULLSCREEN;

        window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
        if (window == nullptr) {
            SDL_Log("Failed to create window: %s", SDL_GetError());
            clean();
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == nullptr) {
            SDL_Log("Failed to create renderer: %s", SDL_GetError());
            SDL_DestroyWindow(window);
            SDL_Quit();
            clean();
        }else
            SDL_Log("Created renderer and Window");
        isRunning = true;
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Set the background color to white
        SDL_Log("SubSystem Initialed");
        cursorG = new Cursor("assets/cursor.png" , 100,100);
        background = new Background("assets/back.bmp");
        playerBase = new PlayerBase("assets/base.png", 300,300, cursorG);
        handler->addObject(playerBase);
        handler->addObject(cursorG);

    }
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            handler->handleEvents(&event);
            break;

    }

}

void Game::update() {
    background->Update();  // update background
    handler->Update();
}

void Game::render() {
    SDL_RenderClear(renderer);
    background->Render();  // render background
    handler->Render();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    SDL_Log("Game cleaned and Closed!");
}

bool Game::running() const {
    return isRunning;
}

void Game::addObject(GameObject &object) {
    handler->addObject(&object);
}

void Game::removeObject(GameObject &object) {
    handler->removeObject(&object);
}
