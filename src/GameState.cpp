#include "GameState.hpp"

GameState::GameState()
{
    this->round = 0;
    this->prize = 64;
    this->isOngoing = true;
}

GameState::~GameState()
{
}

int GameState::getRound() const
{
    return this->round;
}

long int GameState::getPrize() const
{
    return this->prize;
}

bool GameState::isGameOngoing()
{
    return this->isOngoing;
}

void GameState::showInventory()
{
    this->table->showInventory();
}

bool GameState::isEmpty()
{
    return this->table->isEmpty();
}
