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

    // Calculate the distance to the target
    double magnitude = sqrt(velX * velX + velY * velY);

    // Normalize the velocity vector
    double normVelX = velX / magnitude;
    double normVelY = velY / magnitude;

    // Calculate speed (adjust as necessary for gameplay)
    double speed = magnitude / 200.0f;  // Example speed factor (adjust as needed)
    if (speed < 0.5) speed = 0.5; // Set a minimum speed threshold

    // Scale the normalized velocities by the speed
    velX = normVelX * speed;
    velY = normVelY * speed;

    // Adjust the target coordinates if necessary
    int adjustedTargetY = targetY + 30; // Adjusting based on game logic

    // Create and add the missile object
    Game::handler->addObject(new Missile(nullptr, startingX, 0,
                                         velX, velY,
                                         targetX, adjustedTargetY,
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
