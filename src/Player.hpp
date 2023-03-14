#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "InventoryHolder.hpp"
#include "Ability.hpp"
#include "Card.hpp"
#include "Deck.hpp"
#include <string>
#include <iostream>
using namespace std;

class Player : 
    public InventoryHolder, 
    public Ability
    {
private:
    string playerName;
    long int point;
    Ability* ability;
public:
    Player();
    Player(string);
    ~Player();

    //getter
    string getPlayerName() const;
    long int getPlayerPoint() const;

    //setter
    void setPlayerPoint(long int);
    void setPlayerAbility(string);

    /*Player method*/
    void showPlayerInfo() const;
    string action();
    void drawCards(int, Deck*);

    /*operator overloads*/
    bool operator>(Player&);
    bool operator<(Player&);
    bool operator==(Player&);
    
    /*function from parent class inheritance*/
    /*Ability member functions*/
    //TBD
    // void action_half();
    // void action_reroll();
    // void action_quadruple();
    // void action_quarter();
    // void action_reverse();
    // void action_swapcard();
    // void action_switch();
    // void action_abilityless();
};

#endif