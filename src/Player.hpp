#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "InventoryHolder.hpp"
#include "Inventory.hpp"
#include "Ability.hpp"
#include "Generics.hpp"
#include <string>
#include <iostream>
using namespace std;

class Deck;

class Player : 
    public InventoryHolder, 
    public Ability
    {
private:
    string playerName;
    long int point;
    Ability* ability;
    InventoryHolder* hand;
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
    void initializeHand();
    void clearHand();

    /*Player method*/
    void showPlayerInfo() const;
    string action();

    /*operator overloads*/
    bool operator>(Player&);
    bool operator<(Player&);
    bool operator==(Player&);

    /*inheritance methods*/
    //inventoryHolder
    bool isEmpty();
    void showInventory() const;
    vector<Card>& getInventory();
    vector<Card>& operator+=(Card&);
    vector<Card>& operator-=(Card&);
    vector<Card>& operator+(Card&);
    vector<Card>& operator-(Card&);
    vector<Card>& operator=(const vector<Card>&);
};

#endif