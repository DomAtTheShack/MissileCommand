//
// Created by dominichann on 8/26/24.
//

#include "../SettingsWindow.h"
#include <iostream>
#include <ostream>
#include <SDL.h>
#include <unistd.h>
#include "../Button.h"

#include "../Window.h"
#include "../ClickableObject.h"



void SettingsWindow::init() {
    std::cout << "Settings Window Initialized!" << std::endl;
    Button* btn = new Button(100, 100, 128, 32, "Hello");

    btn->onClick = [this]() {
        std::cout << "Transferring Window..." << std::endl;

        // 1. Clear old objects so they don't appear in the new window
        handler->removeAllObjects();

        // 2. Create the new Window Wrapper (Reusing Renderer/Handler)
        Window* nextWin = Window::transferWindow(this);

        // 3. Configure the new window
        nextWin->setWindowSize(128, 64);
        nextWin->setWindowTitle("Balls");

        // 4. THE FIX: Store it and Request Transfer
        this->setNextWindow(nextWin);
        this->requestTransfer(); // Sets transferRequested = true
    };

    handler->addObject(btn);
}

void SettingsWindow::clean() {
    SDL_Log("Game cleaned and Closed!");
    Window::clean();
}
void SettingsWindow::render() {
    SDL_RenderClear(renderer);
    handler->Render();
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderPresent(renderer);
}

void SettingsWindow::handleEvents() {
    Window::handleEvents();


}



