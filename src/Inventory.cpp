#include "Inventory.hpp"

Inventory::Inventory()
{
    vector<Card> x;
    this->inventory = x;
    cout << "Inventory initiated" << endl;
}

Inventory::~Inventory()
{
}
vector<Card>& Inventory::operator+=(Card& input){
    this->inventory.push_back(input);
    return this->inventory;
}
vector<Card>& Inventory::operator-=(Card& input){
    for (int i = 0; i < this->inventory.size(); i++)
    {
        if (this->inventory[i] == input){
            this->inventory.erase(this->inventory.begin() + i);
            break;
        } else if (i == this->inventory.size()-1){
            //throw notFoundException;
            cout << "Card not found" << endl;
        }
    }
    return this->inventory;
}
bool Inventory::isEmpty(){
    return this->inventory.empty();
}
vector<Card>& Inventory::operator+ (Card& b){
    return *this += b;
}
vector<Card>& Inventory::operator- (Card& b){
    return *this -= b;
}
vector<Card> &Inventory::operator=(const vector<Card> &input)
{
    this->inventory = input;
    return this->inventory;
}
vector<Card> &Inventory::getInventory()
{
    return this->inventory;
}
void Inventory::showInventory() const{
    for (int i = 0; i < this->inventory.size(); i++)
    {
        cout <<"[" << i+1 << "] " << this->inventory[i] << endl;
    }
}