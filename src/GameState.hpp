#ifndef __GAMESTATE_HPP__
#define __GAMESTATE_HPP__

#include "InventoryHolder.hpp"
#include "Card.hpp"

class GameState: public InventoryHolder<Card>{
private:
    //vector <Card> inventory dari inventoryholder
    int round;
    static long int prize;
    static bool isOngoing;
public:
    GameState();
    ~GameState();
    int getRound();
    long int getPrize();
    bool isGameOngoing();

    //inheritance methods
    void showInventory();
    bool isEmpty();
};

#endif