//
// Created by dominichann on 4/28/24.
//

#include <iostream>
#include "SDL_image.h"
#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

Game::Game() {
    nextID = 0;
}

Game::~Game() {

}

GameObject* player;
SDL_Renderer* Game::renderer = nullptr;

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
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Set the background color to purple
        SDL_Log("SubSystem Initialed");
    }
    player = new GameObject("../assets/player.png"  , 100, 100);
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
            break;

    }

}

void Game::update() {
    player->Update();
}

void Game::render() {
    SDL_RenderClear(renderer);
    player->Render();
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
