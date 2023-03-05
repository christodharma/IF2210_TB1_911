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
    return playerInventory->isEmpty();
}

// void Player::showInventory(){
//     for (vector<Card>::const_iterator i = this->playerInventory->begin(); i != this->playerInventory->end(); ++i){
//         i->printCard();
//     }
// }