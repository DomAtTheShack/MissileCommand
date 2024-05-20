#include "../PlayerBase.h"
#include "../Cursor.h"
#include "../Game.h"
#include "../MissileTrail.h"
#include "../Missile.h"
#include <iostream>
#include <cmath>

PlayerBase::PlayerBase(const char *textureFile, float x, float y, Cursor* cursor) :
        GameObject(textureFile, x, y), cursorInPlay(cursor), fired(false) {}

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
}

void PlayerBase::Render() {
    GameObject::Render();
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
        float speed = 16.0f;

        // Scale the normalized vector to the desired speed
        float scaledVX = normVX * speed;
        float scaledVY = normVY * speed;

        Game::handler->addObject(new Missile(nullptr, xPos, yPos, scaledVX, scaledVY, x, y, true));
        Game::audioSystem->PlayCurrentWAV();
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
