//
// Created by dominichann on 4/29/24.
//

#include <vector>
#include "GameObject.h"

#ifndef MISSILECOMMAND_HANDLER_H
#define MISSILECOMMAND_HANDLER_H

class Handler
        {
public:
    void Update();
    void Render();

    void addObject(GameObject *object);
    void removeObject(GameObject *object);

    static bool isUp();
    static void setUp(bool up);
    static bool isDown();
    static void setDown(bool down);
    static bool isRight();
    static void setRight(bool right);
    static bool isLeft();
    static void setLeft(bool left);

    std::vector<GameObject *> GameObjects;

    void handleEvents(SDL_Event *pEvent);

    void toDestroy();

private:
    static bool up;
    static bool down;
    static bool right;
    static bool left;
    static std::vector<int> IDsInPlay;
    std::vector<GameObject*> objectsToDestroy;
};


#endif //MISSILECOMMAND_HANDLER_H
