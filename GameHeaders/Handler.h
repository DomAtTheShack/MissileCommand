//
// Created by dominichann on 4/29/24.
//

#include <vector>
#include "GameObject.h"
#include "GameID.h"

#ifndef MISSILECOMMAND_HANDLER_H
#define MISSILECOMMAND_HANDLER_H

class Handler
        {
public:
    void Update();
    void Render();

    void addObject(GameObject *object);
    void removeObject(GameObject *object);

    void updateKeys(SDL_Event* keypress);

    bool isUp() const;
    void setUp(bool up);
    bool isDown() const;
    void setDown(bool down);
    bool isRight() const;
    void setRight(bool right);
    bool isLeft() const;
    void setLeft(bool left);

    std::vector<GameObject *> GameObjects;
private:
    bool up;
    bool down;
    bool right;
    bool left;
    static std::vector<int> IDsInPlay;
};


#endif //MISSILECOMMAND_HANDLER_H
