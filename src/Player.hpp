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
    ~Player();

    //getter
    string getPlayerName();
    long int getPlayerPoint();

    /*operator overloads*/
    //REMEMBER TO "DRY"
    vector<Card*>& operator+=(Card&);
    vector<Card*>& operator-=(Card&);
    
    /*function from parent class inheritance*/
    /*Inventory member functions*/
    void showInventory();
    bool isEmpty();
    vector<Card*>& getInventory();
};

#endif