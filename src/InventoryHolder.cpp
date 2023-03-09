#include "InventoryHolder.hpp"
#include "Card.hpp"
#include <vector>
#include <iostream>
using namespace std;

CardInventory::CardInventory(){
    vector<pair<char,int>> x;
    this->inventory = x;
};

CardInventory::~CardInventory(){
    // for (int i = 0; i < this->inventory.size(); i++)
    // {
    //     delete this->inventory[i];
    // }
    // // perlu coba kalo pakai c++ 11 / pakai linux
    // // for (auto p : this->inventory){
    // //     delete p;
    // // }
}

vector<pair<char,int>>& CardInventory::operator+=(Card& input){
    pair<char,int> inputPair(input.getWarna(), input.getAngka());
    this->inventory.push_back(inputPair);
    return this->inventory;
}
vector<pair<char,int>>& CardInventory::operator-=(Card& input){
    int pos;
    for (int i = 0; i < this->inventory.size(); i++)
    {
        if (this->inventory[i].first == input.getWarna() && this->inventory[i].second == input.getAngka()){
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
        cout << i+1 << ".(" << this->inventory[i].first << "," << this->inventory[i].second << ")" << endl;
    }
}

vector<pair<char,int>>& CardInventory::operator+ (Card& b){
    return *this += b;
}
vector<pair<char,int>>& CardInventory::operator- (Card& b){
    return *this -= b;
}

vector<pair<char,int>>& CardInventory::getInventory(){
    return this->inventory;
}