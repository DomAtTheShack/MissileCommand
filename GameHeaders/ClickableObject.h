//
// Created by dooli on 2026/01/28.
//


#ifndef MISSILECOMMAND_CLICKABLEOBJECT_H
#define MISSILECOMMAND_CLICKABLEOBJECT_H
#include "GameObject.h"


// Add a callback function pointer or virtual method for what happens when clicked
#include <functional>

class ClickableObject : public GameObject {
public:
    ClickableObject(int x, int y, int w, int h, const char* textureFile);

    void Update();

    void Render();

    // Override the input handler
    void HandleInput(SDL_Event* event) override;

    // Helper to check bounds (renamed for clarity)
    bool isMouseInside() const;

    // A simple boolean to check externally if needed
    bool isClicked = false;

    // Optional: A function to run when clicked
    std::function<void()> onClick;

protected:
    int w, h;
    bool mouseOver;
};


#endif //MISSILECOMMAND_CLICKABLEOBJECT_H