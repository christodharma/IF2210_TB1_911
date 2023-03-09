#ifndef __GAMESTATE_HPP__
#define __GAMESTATE_HPP__

#include "InventoryHolder.hpp"
#include "Card.hpp"

class GameState: public InventoryHolder{
private:
    InventoryHolder* table;
    int round;
    static long int prize;
    static bool isOngoing;
public:
    GameState();
    ~GameState();
    int getRound() const;
    long int getPrize() const;
    bool isGameOngoing();

    //inheritance methods
    void showInventory();
    bool isEmpty();
};

#endif