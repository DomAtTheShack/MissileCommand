//
// Created by dominichann on 8/18/24.
//

#include "../EnemyMissileLauncher.h"
#include "../Missile.h"
#include "../Game.h"
#include "../CityTargets.h"

EnemyMissileLauncher::EnemyMissileLauncher(const char *texture, int x, int y, Timer* missileTimer, Game* game)
        : GameObject(texture, x, y)
        {
            // Dereference the pointer to assign
            this->missileTimer = missileTimer;
            this->game = game;
        }

void EnemyMissileLauncher::Update() {
    GameObject::Update();
    if(missileTimer->isRunning())
        missileTimer->update();

    if(missileTimer->isFinished())
    {

    }
}

void EnemyMissileLauncher::Render() {
    GameObject::Render();

}

void EnemyMissileLauncher::createMissile(City* cityToHit)
{

    CityTarget target = getCity(cityToHit->getCityNum(),Game::randomNumberGen(0,2));
    // Create and add the missile object
    Game::handler->addObject(new Missile(nullptr, target.startingX, 0,
                                         target.velX, target.velY,
                                         cityToHit->getX() + target.killPointModX, cityToHit->getY() + target.killPointModY,
                                         false));
}




void EnemyMissileLauncher::StartMissile(int difficulty)
{
    numberOfMissiles = (difficulty % 10) * 10;

    int thisMax = Game::randomNumberGen(2, 4);


    if(thisMax > numberOfMissiles)
        thisMax = numberOfMissiles;


    createMissile(game->getCity(Game::randomNumberGen(0,5)));


    missileTimer->start();
}
