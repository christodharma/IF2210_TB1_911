#include "Table.hpp"

Table::Table()
{
    this->_table = new Inventory();
}

Table::~Table()
{
    delete this->_table;
} 

void Table::showInventory() const
{
    cout << "Table: ";
    for (int i = 0; i < this->_table->getInventory().size(); i++)
    {
        cout << this->_table->getInventory()[i] << " ";
    }
    
    cout << endl;
}