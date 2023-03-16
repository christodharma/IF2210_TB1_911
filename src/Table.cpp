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

vector<Card> &Table::getInventory()
{
    return this->_table->getInventory();
}

vector<Card> &Table::operator+=(Card &input)
{
    return *this->_table += input;
}

vector<Card>& Table::operator-=(Card& input){
    return *this->_table -= input;
}
vector<Card>& Table::operator+(Card& input){
    return this->_table->operator+(input);
}
vector<Card>& Table::operator-(Card& input){
    return this->_table->operator-(input);
}
vector<Card>& Table::operator=(const vector<Card>& src){
    return this->_table->operator=(src);
}