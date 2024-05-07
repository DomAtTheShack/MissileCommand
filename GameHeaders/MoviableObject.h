//
// Created by dominichann on 5/7/24.
//

#ifndef MISSILECOMMAND_MOVIABLEOBJECT_H
#define MISSILECOMMAND_MOVIABLEOBJECT_H


#include "GameObject.h"

class MoviableObject : public GameObject
{
public:
    MoviableObject(const char *textureFile, int x, int y);
    ~MoviableObject();

    void Update() override;
    void Render() override;

private:
    int velX;
    int velY;
    

};


#endif //MISSILECOMMAND_MOVIABLEOBJECT_H
