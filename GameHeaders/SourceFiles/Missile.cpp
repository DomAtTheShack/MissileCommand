#include "../Missile.h"#include "../Game.h"#include "../MissileExplo.h"#include "libAssets.h"#include <cmath>std::pair<std::string, std::string> Missile::missileSFX = {};bool Missile::madeSFX = false;Missile::Missile(const char *textureFile, float x, float y, float vX, float vY, float kpX, float kpY, bool baseMissile)        : MoviableObject(textureFile, x, y, vX, vY), killPointX(kpX), killPointY(kpY), Trail(nullptr)        {    if(!madeSFX)    {        madeSFX = true;        missileSFX = getAsset("sfx/shoot.wav");    }    if(!baseMissile)        createTrail();    else {        Game::audioSystem->LoadWAV(missileSFX.first.c_str(), false);        Game::audioSystem->PlayCurrentWAV();    }    baseMiss = baseMissile;    color = {0, 0, 0, 255};}Missile::~Missile(){        if(!baseMiss)            Game::handler->removeObject(Trail);        Game::handler->removeObject(this);};void Missile::Update() {    // Check if the missile has reached or passed the kill point    if ((velX > 0 && xPos >= killPointX) || (velX < 0 && xPos <= killPointX) ||        (velY > 0 && yPos >= killPointY) || (velY < 0 && yPos <= killPointY)) {        if(!baseMiss)            Game::handler->removeObject(Trail);        Game::handler->removeObject(this);        Game::handler->addObject(new MissileExplo(nullptr,xPos,yPos));        return; // Exit the update function to prevent further updates    }    MoviableObject::Update();}void Missile::Render() {    SDL_SetRenderDrawColor(Game::renderer, color.r, color.g, color.b,color.a);    SDL_Rect square = {static_cast<int>(xPos), static_cast<int>(yPos), 10, 8};    SDL_RenderFillRect(Game::renderer, &square);}void Missile::createTrail() {    Trail = new MissileTrail(nullptr, xPos - 10, yPos - 10, velX, velY);    Game::handler->addObject(Trail);}void Missile::TargetBase() {    // Optional: Implement targeting logic if needed}std::string Missile::getObjectType() {    return "Missile";}bool Missile::isFriendly() const{    return baseMiss;}MissileTrail* Missile::getTrail(){    return Trail;}