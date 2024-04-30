#include "../Background.h"
#include "../TextureManager.h"

Background::Background(const char *texturesheet) : GameObject(texturesheet, 0, 0) {}

Background::~Background() = default;

void Background::Update() {
    srcRect.h = 538;
    srcRect.w = 226;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = 0;
    destRect.y = 0;

    // Use SDL's function to get the window size
    int windowWidth, windowHeight;
    SDL_GetWindowSize(Game::window, &windowWidth, &windowHeight);

    destRect.w = windowWidth;
    destRect.h = windowHeight;
}

void Background::Render() {
    GameObject::Render(); // Call the render method of the base class
}