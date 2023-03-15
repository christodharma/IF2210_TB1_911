#ifndef __GAMEMANAGER_HPP__
#define __GAMEMANAGER_HPP__

#include "GameState.hpp"
#include "Player.hpp"

class GameManager
{
private:
    GameState* gameState;
    Player* players;
public:
    GameManager(GameState*&, Player*&);
    ~GameManager();

    GameState* getGameState();
    Player* getPlayers();
};

#endif