#include "InventoryHolder.hpp"
#include "Card.hpp"
#include <vector>
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

vector<Card*>& CardInventory::operator+(Card& input){
    Card* inputPtr(&input);
    this->inv.push_back(inputPtr);
    return this->inv;
}
vector<Card*>& CardInventory::operator-(Card& input){
    // Card* inputPtr(&input);
    // this->inv.erase(inputPtr);
    for (auto i = inv.begin(); i != inv.end(); i++)
    {
        if (**i == input){
            // Card* inputPtr(*i);
            cout << "found card to be erased" << endl;
            this->inv.erase(i);
        }
    }
    return this->inv;
}

bool CardInventory::isEmpty(){
    return inv.empty();
}
void CardInventory::showInventory(){
    for (int i = 0; i < inv.size(); i++)
    {
        inv[i]->printCard();
    }
}

vector<Card*>& CardInventory::getInventory(){
    return this->inv;
}