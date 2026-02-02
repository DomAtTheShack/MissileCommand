#ifndef MISSILECOMMAND_BUTTON_H
#define MISSILECOMMAND_BUTTON_H

#include "ClickableObject.h"
#include <SDL_ttf.h>

class Button : public ClickableObject {
public:
    // Use const char* for string literals (like "Hello")
    Button(int x, int y, int w, int h, const char* text);
    
    // Destructor to clean up the text texture
    ~Button();

    // Override Render to draw background AND text
    void Render() override;
    void Update() override;

    void setText(const char* text);

private:
    SDL_Texture* textTexture = nullptr;
    SDL_Rect textRect; // Stores where the text goes (centered)
};

#endif