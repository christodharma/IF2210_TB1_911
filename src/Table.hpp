#ifndef __TABLE_HPP__
#define __TABLE_HPP__

#include "InventoryHolder.hpp"

class Table : virtual public InventoryHolder
{
public:
    Table();
    ~Table();
    void showTable();
};

#endif