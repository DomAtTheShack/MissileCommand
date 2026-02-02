#include "../Button.h"
#include "../Window.h" // Access Window::renderer and Window::defaultFont
#include <iostream>

Button::Button(int x, int y, int w, int h, const char *text) 
    : ClickableObject(x, y, w, h, "assets/images/button.png")
{
    // 1. Ensure the clickable area matches the visual size
    destRect.x = x;
    destRect.y = y;
    destRect.w = w;
    destRect.h = h;

    // 2. Safety Check: Is the font loaded?
    if (Window::defaultFont == nullptr) {
        std::cerr << "Error: Window::defaultFont is NULL. Text will not render." << std::endl;
        return;
    }

    // 3. Create the Text
    SDL_Color textColor = {0, 0, 0, 255}; // Black Text (Alpha 255 is opaque)
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Window::defaultFont, text, textColor);

    if (surfaceMessage) {
        textTexture = SDL_CreateTextureFromSurface(Window::renderer, surfaceMessage);
        
        // 4. Center the Text Logic
        // Get the size of the text itself
        textRect.w = surfaceMessage->w;
        textRect.h = surfaceMessage->h;
        
        // Math: x + (ContainerWidth - TextWidth) / 2
        textRect.x = x + (w - textRect.w) / 2;
        textRect.y = y + (h - textRect.h) / 2;

        // Clean up the surface (we only need the texture now)
        SDL_FreeSurface(surfaceMessage);
    } else {
        std::cerr << "Failed to render text surface: " << TTF_GetError() << std::endl;
    }
}

Button::~Button() {
    // Clean up the texture when the button is deleted
    if (textTexture) {
        SDL_DestroyTexture(textTexture);
    }
}

void Button::Render() {
    // 1. Draw the Button Image (Handled by Parent)
    ClickableObject::Render(); 

    // 2. Draw the Text on Top
    if (textTexture) {
        SDL_RenderCopy(Window::renderer, textTexture, NULL, &textRect);
    }
}

void Button::Update() {
    ClickableObject::Update();
}

void Button::setText(const char *text) {
    SDL_Color textColor = {0, 0, 0, 255}; // Black Text (Alpha 255 is opaque)
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Window::defaultFont, text, textColor);
    if (surfaceMessage) {
        textTexture = SDL_CreateTextureFromSurface(Window::renderer, surfaceMessage);

        // 4. Center the Text Logic
        // Get the size of the text itself
        textRect.w = surfaceMessage->w;
        textRect.h = surfaceMessage->h;

        // Math: x + (ContainerWidth - TextWidth) / 2
        textRect.x = textRect.x + (w - textRect.w) / 2;
        textRect.y = textRect.y + (h - textRect.h) / 2;

        // Clean up the surface (we only need the texture now)
        SDL_FreeSurface(surfaceMessage);
    } else {
        std::cerr << "Failed to render text surface: " << TTF_GetError() << std::endl;
    }

}

