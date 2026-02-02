//
// Created by dooli on 2026/01/28.
//

#include "../ClickableObject.h"

#include <iostream>

#include "../GameObject.h"
#include "../Window.h"


ClickableObject::ClickableObject(int x, int y, int w, int h, const char* textureFile) : GameObject(textureFile ,x, y)
{
    this->h = h;
    this->w = w;
    mouseOver = false;
    destRect.w = w;
    destRect.h = h;
}



void ClickableObject::Update() {
    GameObject::Update();
}

void ClickableObject::Render() {
    GameObject::Render();
}

void ClickableObject::HandleInput(SDL_Event* event) {
    // 1. Check if the event is a mouse click
    if (event->type == SDL_MOUSEBUTTONDOWN) {
        // 2. Check if it was the Left Mouse Button
        if (event->button.button == SDL_BUTTON_LEFT) {
            // 3. Check if the mouse is inside THIS object
            if (isMouseInside()) {
                std::cout << "Object Clicked!" << std::endl;
                isClicked = true;
                if (onClick) onClick();
            }
        }
    }

    // Reset click state on mouse up (optional, depends on game logic)
    if (event->type == SDL_MOUSEBUTTONUP) {
        isClicked = false;
    }
}



bool ClickableObject::isMouseInside() const {
    // We can use the static Window mouse pos we fixed earlier
    std::pair<int, int> mousePos = Window::getMousePos();
    SDL_Point clickPoint = { mousePos.first, mousePos.second };
    return SDL_PointInRect(&clickPoint, &destRect);
}