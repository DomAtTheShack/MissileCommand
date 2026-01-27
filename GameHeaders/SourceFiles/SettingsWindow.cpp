//
// Created by dominichann on 8/26/24.
//

#include "../SettingsWindow.h"
#include <iostream>
#include <ostream>
#include <SDL.h>
#include "../Window.h"



void SettingsWindow::init() {
    std::cout << "Settings Window Initialized!" << std::endl;
}

void SettingsWindow::clean() {
    SDL_Log("Game cleaned and Closed!");
    Window::clean();
}
void SettingsWindow::render() {
    SDL_RenderClear(renderer);
    handler->Render();
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderPresent(renderer);
}

void SettingsWindow::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        // 1. Call Parent "Basic" Logic
        handleBasicEvents(event);

        // 2. specific code for this window
        if (event.type == SDL_MOUSEBUTTONUP) {
            this->transferRequested = true;
        }
    }
}

