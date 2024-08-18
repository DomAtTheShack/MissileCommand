//
// Created by dominichann on 8/18/24.
//

#ifndef MISSILECOMMAND_ENEMYMISSILELAUNCHER_H
#define MISSILECOMMAND_ENEMYMISSILELAUNCHER_H


#include "../GameObject.h"
#include "../Timer.h"
#include "../City.h"
#include "../Game.h"

class EnemyMissileLauncher : public GameObject
        {
public:
        EnemyMissileLauncher(const char *texture, int x, int y,
                             Timer* missileTimer, Game* game);

        ~EnemyMissileLauncher() = default;

        void Update() override;
        void Render() override;

        void StartMissile(int difficulty);

private:

    void createMissile(City* cityToHit, int startingX, int speedFactor);
    Timer* missileTimer;
    int numberOfMissiles;
    Game* game;
};


#endif //MISSILECOMMAND_ENEMYMISSILELAUNCHER_H
