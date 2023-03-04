#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "InventoryHolder.hpp"
#include "Ability.hpp"
#include <iostream>
using namespace std;

class Player : 
    InventoryHolder, 
    // Card, //antara inherit card / valueable / gapake (soalnya ada inventoryholder)
    Ability
    {
private:
    string playerName;
    long int point;
public:
    Player();
    Player(string);
    string getPlayerName();
    long int getPlayerPoint();
    void showInventory();
};

#endif