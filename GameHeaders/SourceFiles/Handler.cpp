//
// Created by dominichann on 4/29/24.
//

#include "../Handler.h"
#include <algorithm> //Needed for std::remove

bool Handler::isUp() const {
    return up;
}

void Handler::setUp(const bool up) {
    this->up = up;
}

bool Handler::isDown() const {
    return down;
}

void Handler::setDown(const bool down) {
    this->down = down;
}

bool Handler::isRight() const {
    return right;
}

void Handler::setRight(const bool right) {
    this->right = right;
}

bool Handler::isLeft() const {
    return left;
}

void Handler::setLeft(const bool left) {
    this->left = left;
}

void Handler::Update() {
    for (GameObject *x: GameObjects) {
        x->Update();
    }
}

void Handler::Render() {
    for (GameObject *x: GameObjects) {
        x->Render();
    }
}

void Handler::removeObject(GameObject *object) {
    auto it = std::find(GameObjects.begin(), GameObjects.end(), object);
    if (it != GameObjects.end()) {
        delete *it;  // Deallocate memory
        GameObjects.erase(it); // Remove from vector
    }
}

void Handler::addObject(GameObject *object) {
    GameObjects.push_back(object);
}

