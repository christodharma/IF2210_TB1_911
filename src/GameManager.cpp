#include "GameManager.hpp"

GameManager::GameManager(GameState* g, Player* p)
{
    this->gameState = g;
    this->players = p;
}

GameManager::~GameManager()
{
    delete gameState;
}

GameState* GameManager::getGameState(){
    return this->gameState;
}

Player* GameManager::getPlayers(){
    return this->players;
}