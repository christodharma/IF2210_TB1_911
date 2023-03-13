#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "InventoryHolder.hpp"
#include "Ability.hpp"
#include <string>
#include <iostream>
using namespace std;

class Player : 
    public InventoryHolder 
    // public Ability
    {
private:
    InventoryHolder* playerInventory;
    string playerName;
    long int point;
public:
    Player();
    Player(string);
    ~Player();

    //getter
    string getPlayerName() const;
    long int getPlayerPoint() const;

    /*Player method*/
    void showPlayerInfo();
    void inputAction();
    void action_next();
    void action_double();

    /*operator overloads*/
    vector<Card>& operator+=(Card&);
    vector<Card>& operator-=(Card&);
    vector<Card>& operator+(Card&);
    vector<Card>& operator-(Card&);
    
    /*function from parent class inheritance*/
    /*Inventory member functions*/
    void showInventory();
    bool isEmpty();
    vector<Card>& getInventory();

    /*Ability member functions*/
    //TBD
    void action_half();
    void action_reroll();
    void action_quadruple();
    void action_quarter();
    void action_reverse();
    void action_swapcard();
    void action_switch();
    void action_abilityless();
};

#endif