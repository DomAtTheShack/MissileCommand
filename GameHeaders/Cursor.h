//
// Created by Dominic Hann on 5/6/24.
//

#ifndef MISSILECOMMAND_CURSOR_H
#define MISSILECOMMAND_CURSOR_H
#define DEFAULT_CUR_SPEED 4


#include "GameObject.h"
#include "PlayerBase.h"

class Cursor : public GameObject
{
public:
    Cursor(const char *textureFile, int x, int y);
    ~Cursor();

    void Update() override;
    void Render() override;

    int getX() const;
    int getY() const;

    void HandleInput(SDL_Event *event) override;
private:
    int velX;
    int velY;
    bool fired;

    int cursSpeed;

};


#endif //MISSILECOMMAND_CURSOR_H
