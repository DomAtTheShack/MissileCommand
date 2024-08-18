//
// Created by dominichann on 8/18/24.
//

#include "EnemyMissileLauncher.h"
#include "../Missile.h"
#include "../Game.h"

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

void EnemyMissileLauncher::createMissile(City* cityToHit, int startingX, int speedFactor)
{
    int targetX = cityToHit->getX();
    int targetY = cityToHit->getY();
    int velY = targetY; // The distance in Y direction
    int velX = targetX - startingX; // The distance in X direction

    // Calculate the number of steps needed to reach the target
    double magnitude = sqrt(velX * velX + velY * velY);

    // To reach the target exactly, scale the velocities so that the missile travels in exactly `magnitude` steps
    double normVelX = velX / magnitude;
    double normVelY = velY / magnitude;

    // Choose a speed that corresponds to the distance
    double speed = magnitude / 340.0f;  // Example speed factor (adjust as needed)

    velX = normVelX * speed;
    velY = normVelY * speed;

    Game::handler->addObject(new Missile(nullptr, startingX, 0,
                                         velX, velY,
                                         targetX, targetY,
                                         false));
}



void EnemyMissileLauncher::StartMissile(int difficulty)
{
    numberOfMissiles = (difficulty % 10) * 10;
    int speedMulti = (difficulty % 10);

    int thisMax = Game::randomNumberGen(2, 4);


    if(thisMax > numberOfMissiles)
        thisMax = numberOfMissiles;

    for(int i = 0;i < thisMax; i ++)
    {
        int cityToShoot = Game::randomNumberGen(0,5);
        int startX = Game::randomNumberGen(0,1200);
        createMissile(game->getCity(cityToShoot), startX, speedMulti);
    }

    missileTimer->start();
}
