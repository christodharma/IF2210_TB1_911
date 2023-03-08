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
    for (int i = 0; i < this->inv.size(); i++)
    {
        delete this->inv[i];
    }
    // perlu coba kalo pakai c++ 11 / pakai linux
    // for (auto p : this->inv){
    //     delete p;
    // }
}

vector<Card*>& CardInventory::operator+=(Card& input){
    this->inv.push_back(new Card(input));
    return this->inv;
}
vector<Card*>& CardInventory::operator-=(Card& input){
    int pos;
    for (int i = 0; i < this->inv.size(); i++)
    {
        if (*this->inv[i] == input){
            pos = i;
            break;
        }
    }
    // delete this->inv[pos]; //ada ini malah melambat, justru karena didelete harus gitu atau ada error
    //// mungkin karena ada dtor dan ada itu, jadi 2 kali delete?
    this->inv.erase(this->inv.begin()+pos);
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

vector<Card*>& CardInventory::operator+ (Card& b){
    return *this += b;
}
vector<Card*>& CardInventory::operator- (Card& b){
    return *this -= b;
}

vector<Card*>& CardInventory::getInventory(){
    return this->inv;
}