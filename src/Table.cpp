#include "Table.hpp"

Table::Table() : InventoryHolder()
{
    cout << "Table initiated" << endl;
}

Table::~Table()
{
} 

void Table::showTable()
{
    cout << "Table: ";
    for (int i = 0; i < this->inventory.size(); i++)
    {
        cout << this->inventory[i] << " ";
    }
    cout << endl;
}