#ifndef __INVENTORY_HPP__
#define __INVENTORY_HPP__

#include "InventoryHolder.hpp"
#include <vector>
#include <iostream>

class Inventory : public InventoryHolder
{
private:
    vector<Card> inventory;
public:
    Inventory();
    ~Inventory();
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