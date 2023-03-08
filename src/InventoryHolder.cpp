#include "InventoryHolder.hpp"
#include "Card.hpp"
#include <vector>
#include <iostream>
using namespace std;

CardInventory::CardInventory(){
    vector<Card*> x;
    this->inventory = x;
};

CardInventory::~CardInventory(){
    for (int i = 0; i < this->inventory.size(); i++)
    {
        delete this->inventory[i];
    }
    // perlu coba kalo pakai c++ 11 / pakai linux
    // for (auto p : this->inventory){
    //     delete p;
    // }
}

vector<Card*>& CardInventory::operator+=(Card& input){
    this->inventory.push_back(new Card(input));
    return this->inventory;
}
vector<Card*>& CardInventory::operator-=(Card& input){
    int pos;
    for (int i = 0; i < this->inventory.size(); i++)
    {
        if (*this->inventory[i] == input){
            pos = i;
            break;
        }
    }
    // delete this->inventory[pos]; //ada ini malah melambat, justru karena didelete harus gitu atau ada error
    //// mungkin karena ada dtor dan ada itu, jadi 2 kali delete?
    this->inventory.erase(this->inventory.begin()+pos);
    return this->inventory;
}

bool CardInventory::isEmpty(){
    return this->inventory.empty();
}

void CardInventory::showInventory(){
    for (int i = 0; i < this->inventory.size(); i++)
    {
        cout << i+1 << ". " << *this->inventory[i] << endl;
    }
}

vector<Card*>& CardInventory::operator+ (Card& b){
    return *this += b;
}
vector<Card*>& CardInventory::operator- (Card& b){
    return *this -= b;
}

vector<Card*>& CardInventory::getInventory(){
    return this->inventory;
}