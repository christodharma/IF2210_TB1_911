#ifndef __TABLE_HPP__
#define __TABLE_HPP__

#include "InventoryHolder.hpp"
#include "Inventory.hpp"
#include "Card.hpp"

class Table : virtual public InventoryHolder
{
private:
    InventoryHolder* _table;
public:
    Table();
    ~Table();
    void showInventory() const;
};

#endif