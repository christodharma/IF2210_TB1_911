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

vector<Card*>& CardInventory::operator+=(Card& input){
    Card* inputPtr(&input);
    this->inv.push_back(inputPtr);
    return this->inv;
}
vector<Card*>& CardInventory::operator-=(Card& input){
    // Card* inputPtr(&input);
    // this->inv.erase(inputPtr);
    auto i = this->inv.begin();
    while (i!=this->inv.end())
    {
        if (**i==input/*&& *i == &input*/){
            i = this->inv.erase(i);
            break;
        }
        i++;
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

// vector<Card*>& operator+ (vector<Card*>& a, Card& b){
//     return a += b;
// }
// vector<Card*>& operator- (vector<Card*>& a, Card& b){
//     return a -= b;
// }

vector<Card*>& CardInventory::getInventory(){
    return this->inv;
}