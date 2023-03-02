#ifndef __INVENTORYHOLDER_HPP__
#define __INVENTORYHOLDER_HPP__

#include "Valueable.hpp"
#include "Ability.hpp"
#include <vector>
#include <string>
using namespace std;

class InventoryHolder{
protected:
    vector<Card*> inventory;
public:
    virtual Card* getInventory();
};

class Player : InventoryHolder, Valueable, Ability{
private:
    Player(string);
    string playerName;
    long int point;
};

class GameState: InventoryHolder, Valueable {
private:
    int round;
    static long int prize;
    static bool isOngoing;
    vector<Card*> tableCard;
};

#endif