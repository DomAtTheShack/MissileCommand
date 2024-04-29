//
// Created by dominichann on 4/29/24.
//

#include "Handler.h"
#include "GameID.h"

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

void Handler::Update()
{

}

void Handler::Render() {

}

void Handler::addObject(GameObject &object)
{
    GameObjects.push_back(object);
}

void Handler::removeObject(ID &objectID)
{

}
