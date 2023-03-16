#ifndef __TABLE_HPP__
#define __TABLE_HPP__

#include "InventoryHolder.hpp"
#include "Inventory.hpp"
#include "Card.hpp"

class Table : public InventoryHolder
{
private:
    InventoryHolder* _table;
public:
    Table();
    ~Table();
    void showInventory() const;
    vector<Card>& getInventory();
    vector<Card>& operator+=(Card&);
    vector<Card>& operator-=(Card&);
    vector<Card>& operator+(Card&);
    vector<Card>& operator-(Card&);
    vector<Card>& operator=(const vector<Card>&);
};

#endif