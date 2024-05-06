//
// Created by Dominic Hann on 5/6/24.
//

#ifndef MISSILECOMMAND_PLAYERBASE_H
#define MISSILECOMMAND_PLAYERBASE_H


#include "GameObject.h"
#include "Cursor.h"

class PlayerBase : public GameObject
{
public:
    PlayerBase(const char *textureFile, int x, int y, Cursor* cursor);
    ~PlayerBase();

    void Render() override;
    void Update() override;

    void fire();
    bool isHit();

private:
    Cursor* cursorInPlay;
};


#endif //MISSILECOMMAND_PLAYERBASE_H
