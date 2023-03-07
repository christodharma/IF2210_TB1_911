#include "InventoryHolder.hpp"
#include "Card.hpp"
#include <vector>
#include <iostream>
using namespace std;

Inventory::Inventory(){
    vector<Card> x;
    this->inventory = x;
};


Inventory::~Inventory(){}

vector<Card>& Inventory::operator+=(Card& input){
    this->inventory.push_back(input); //WARNING push_back Card&
    return this->inventory;
}

//removing input Card object from inventory
vector<Card>& Inventory::operator-=(Card& input){
    auto itr = this->inventory.begin();
    // this->inventory.erase(itr+3);
    // while (itr!=this->inventory.end())
    // {
    //     if (*itr==input){
    //         itr = this->inventory.erase(itr);
    //         break;
    //     } else {
    //         itr++;
    //     }
    // }
    for (int i = 0; i < this->inventory.size(); i++)
    {
        if(this->inventory[i] == input){
            this->inventory.erase(itr+i);
            break;
        }
    }
    return this->inventory;
}

bool Inventory::isEmpty(){
    return this->inventory.empty();
}

void Inventory::showInventory(){
    for (int i = 0; i < this->inventory.size(); i++)
    {
        cout << i+1 << ". " << this->inventory[i] << endl;
    }
}

// vector<Card*>& operator+ (vector<Card*>& a, Card& b){
//     return a += b;
// }
// vector<Card*>& operator- (vector<Card*>& a, Card& b){
//     return a -= b;
// }

vector<Card>& Inventory::getInventory(){
    return this->inventory;
}