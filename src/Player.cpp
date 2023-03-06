#include "InventoryHolder.hpp"
#include "Card.hpp"
#include "Player.hpp"
#include <iostream>
using namespace std;

Player::Player(){
    string name;
    cout<<"Please insert player name: ";
    cin >> name;
    this->playerName = name;
    this->point = 0;
    // this->inventory = null soalnya undefined
}

Player::Player(string name){
    this->playerName = name;
    this->point = 0;
    this->playerInventory = new CardInventory();
}

Player::~Player(){
    //call ulang delete (for contents of playerInventory?) atau udah dipanggil dari dtor cardInventory object? contoh:
    // this->playerInventory->~CardInventory();
    delete this->playerInventory;
}

string Player::getPlayerName(){
    return this->playerName;
}

long int Player::getPlayerPoint(){
    return this->point;
}

bool Player::isEmpty(){
    return this->playerInventory->isEmpty();
}

vector<Card*>& Player::operator+=(Card& input){
    Card* inputPtr(&input);
    this->playerInventory->getInventory().push_back(inputPtr);
    return this->playerInventory->getInventory();
}
vector<Card*>& Player::operator-=(Card& input){
    for (auto i = this->playerInventory->getInventory().begin(); i != this->playerInventory->getInventory().end(); i++)
    {
        if (**i == input){
            // Card* inputPtr(*i);
            cout << "found card to be erased" << endl;
            this->playerInventory->getInventory().erase(i);
        }
    }
    return this->playerInventory->getInventory();
}

void Player::showInventory(){
    // for (auto i = this->playerInventory->getInventory().begin(); i != this->playerInventory->getInventory().end(); ++i){
    //     cout << *i << endl; //cuman print Card*
    // }
    cout << this->playerName << "'s Inventory:" << endl;
    if (this->isEmpty()){
        cout << "-" << endl;
    } else {
        this->playerInventory->showInventory();
    }
}

vector<Card*>& Player::getInventory(){
    return this->playerInventory->getInventory();
}