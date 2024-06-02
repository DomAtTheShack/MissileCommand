//
// Created by dominichann on 4/29/24.
//

#include "../Handler.h"
#include <algorithm> //Needed for std::remove
#include <typeinfo>
#include <iostream>
#include "../PlayerBase.h"

bool Handler::up = false;
bool Handler::down = false;
bool Handler::right = false;
bool Handler::left = false;

bool Handler::isUp() {
    return up;
}

void Handler::setUp(const bool upI) {
    up = upI;
}

bool Handler::isDown() {
    return down;
}

void Handler::setDown(const bool downI) {
    down = downI;
}

bool Handler::isRight() {
    return right;
}

void Handler::setRight(const bool rightI) {
    right = rightI;
}

bool Handler::isLeft() {
    return left;
}

void Handler::setLeft(const bool leftI) {
    left = leftI;
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

void Handler::removeObject(GameObject* object) {
        objectsToDestroy.push_back(object);
}


void Handler::addObject(GameObject *object) {
    GameObjects.push_back(object);
}


void Handler::handleEvents(SDL_Event* pEvent)
{
    // Make a copy of the GameObjects vector
    std::vector<GameObject*> gameObjectsCopy = GameObjects;

    // Iterate over the copy
    for (GameObject* x : gameObjectsCopy) {
        if (x != nullptr) {
            // Check if the object is of type PlayerBase
            try {
                // Call Render and HandleInput methods
                x->HandleInput(pEvent);
            } catch (const std::bad_typeid& e) {
                std::cerr << "Error: typeid could not determine the type of the object." << std::endl;
            }
        } else {
            std::cerr << "Error: Encountered null pointer in GameObjects vector." << std::endl;
        }
    }
}

void Handler::toDestroy() {
    for (int i = 0; i < objectsToDestroy.size(); i++) {
        GameObject* objToDestroy = objectsToDestroy[i];

        // Find the corresponding object in GameObjects vector
        auto it = std::find(GameObjects.begin(), GameObjects.end(), objToDestroy);
        if (it != GameObjects.end()) {
            // Erase the object from GameObjects vector
            GameObjects.erase(it);
            // Deallocate memory
            delete objToDestroy;
        } else {
            // Object not found in GameObjects vector
            std::cerr << "Object to destroy not found in GameObjects vector." << std::endl;
        }
    }
    objectsToDestroy.clear();
}



