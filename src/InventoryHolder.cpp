#include "InventoryHolder.hpp"
#include "Card.hpp"
#include <vector>
#include <iostream>
using namespace std;

InventoryHolder::InventoryHolder(){
    vector<Card> x;
    this->inventory = x;
};

InventoryHolder::~InventoryHolder(){
}

vector<Card>& InventoryHolder::operator+=(Card& input){
    this->inventory.push_back(input);
    return this->inventory;
}
vector<Card>& InventoryHolder::operator-=(Card& input){
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

bool InventoryHolder::isEmpty(){
    return this->inventory.empty();
}

void InventoryHolder::showInventory() const{
    for (int i = 0; i < this->inventory.size(); i++)
    {
        cout << i+1 << "." << this->inventory[i] << endl;
    }
}

vector<Card>& InventoryHolder::operator+ (Card& b){
    return *this += b;
}
vector<Card>& InventoryHolder::operator- (Card& b){
    return *this -= b;
}

vector<Card>& InventoryHolder::getInventory(){
    return this->inventory;
}