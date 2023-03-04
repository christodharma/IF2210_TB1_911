#include "InventoryHolder.hpp"
// #include "Card.hpp"
#include <iostream>
using namespace std;

CardInventory::CardInventory(){
    vector<Card*> x;
    this->inv = x;
};

CardInventory::~CardInventory(){
    for (auto i = this->inv.begin(); i != this->inv.end(); i++)
    {
        delete *i;
    }
    // perlu coba kalo pakai c++ 11 / pakai linux
    // for (auto p : this->inv){
    //     delete p
    // }
}

vector<Card*> CardInventory::getInventory(){
    return this->inv;
}