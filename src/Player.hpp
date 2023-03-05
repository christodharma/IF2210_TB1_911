#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "InventoryHolder.hpp"
#include "Ability.hpp"
#include <iostream>
using namespace std;

class Player : 
    public InventoryHolder<Card> 
    // ,public Card, //antara inherit card / valueable / gapake (soalnya ada inventoryholder)
    // public Ability
    {
private:
    InventoryHolder<Card>* playerInventory;
    string playerName;
    long int point;
public:
    Player();
    Player(string);
    virtual ~Player(); //need virtual to call playerInventory dtor

    //getter
    string getPlayerName();
    long int getPlayerPoint();

    //function from parent class inheritance
    //inventory member functions
    void showInventory();
    bool isEmpty();
};

#endif