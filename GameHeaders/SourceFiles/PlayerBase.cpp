#include "../PlayerBase.h"
#include "../Game.h"
#include "../MissileTrail.h"
#include "../Missile.h"
#include <iostream>
#include <cmath>

PlayerBase::PlayerBase(const char *textureFile, float x, float y, Cursor* cursor) :
        GameObject(textureFile, x, y), cursorInPlay(cursor), fired(false), currentGame(Game::getInstance())
{
    color = {0,0,0,255};
}

PlayerBase::~PlayerBase() = default;

void PlayerBase::Update() {
    GameObject::Update();
    srcRect.x = static_cast<int>(xPos);
    srcRect.y = static_cast<int>(yPos);
    srcRect.h = 2;
    srcRect.w = 5;
    destRect.x = static_cast<int>(xPos + 5);
    destRect.y = static_cast<int>(yPos + 5);
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
    cursorInPlay->Update();
    if(currentGame.missilesLeft() == 0)
        currentGame.reload();
}

void PlayerBase::Render() {
    GameObject::Render();
    RenderMissiles();
}

void PlayerBase::fire(float x, float y) {
    if (Game::handler != nullptr && cursorInPlay != nullptr) {
        // Calculate the velocity vector components
        float vX = x - xPos;
        float vY = y - yPos;

        // Calculate the length of the vector
        float length = std::sqrt(vX * vX + vY * vY);

        // Normalize the velocity vector
        float normVX = vX / length;
        float normVY = vY / length;

        // Define the desired speed
        float speed = 18.0f;

        // Scale the normalized vector to the desired speed
        float scaledVX = normVX * speed;
        float scaledVY = normVY * speed;

        Game::handler->addObject(new Missile(nullptr, xPos, yPos, scaledVX, scaledVY, x, y, true));
        Game::audioSystem->PlayCurrentWAV();
        currentGame.missileShot();
    }
}

int PlayerBase::gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool PlayerBase::isHit() {
    return false;
}

void PlayerBase::HandleInput(SDL_Event* event) {
    if (event->type == SDL_KEYDOWN) {
        switch (event->key.keysym.sym) {
            case SDLK_SPACE:
                if (!fired) {
                    fired = true;
                    fire(static_cast<float>(cursorInPlay->getX()), static_cast<float>(cursorInPlay->getY()));
                }
                break;
            default:
                break;
        }
    }
    if (event->type == SDL_KEYUP) {
        switch (event->key.keysym.sym) {
            case SDLK_SPACE:
                fired = false;
                break;
            default:
                break;
        }
    }
}

void PlayerBase::RenderMissiles()
{
    // Set the color for drawing
    SDL_SetRenderDrawColor(Game::renderer, color.r, color.g, color.b, color.a);
    int totalSquares = 0;

    for (int i = 0; totalSquares < currentGame.missilesLeft(); ++i) {
        int squaresInLevel = i + 1;
        int levelY = BASE_Y + (i * (SQUARE_H)); // Adjust y position for each level
        int startX = BASE_X - (squaresInLevel * (SQUARE_W + SPACING) / 2); // Center the level

        for (int j = 0; j < squaresInLevel && totalSquares < currentGame.missilesLeft(); ++j) {
                int squareX = startX + (j * (SQUARE_W + SPACING));
                SDL_Rect square = {squareX, levelY, SQUARE_W, SQUARE_H};
                SDL_RenderFillRect(Game::renderer, &square);
                ++totalSquares; // Increment the total number of squares drawn
        }
    }
}
