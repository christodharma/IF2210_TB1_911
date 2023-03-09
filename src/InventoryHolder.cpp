#include "InventoryHolder.hpp"
#include "Card.hpp"
#include <vector>
#include <iostream>
using namespace std;

CardInventory::CardInventory(){
    vector<Card> x;
    this->inventory = x;
};

CardInventory::~CardInventory(){
}

vector<Card>& CardInventory::operator+=(Card& input){
    this->inventory.push_back(input);
    return this->inventory;
}
vector<Card>& CardInventory::operator-=(Card& input){
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

bool CardInventory::isEmpty(){
    return this->inventory.empty();
}

void CardInventory::showInventory(){
    for (int i = 0; i < this->inventory.size(); i++)
    {
        cout << i+1 << "." << this->inventory[i] << endl;
    }
}

vector<Card>& CardInventory::operator+ (Card& b){
    return *this += b;
}
vector<Card>& CardInventory::operator- (Card& b){
    return *this -= b;
}

vector<Card>& CardInventory::getInventory(){
    return this->inventory;
}