#include "InventoryHolder.hpp"
#include "Card.hpp"
#include "Player.hpp"
#include <iostream>
using namespace std;

Player::Player(){
    this->playerName = "NoName";
    this->point = 0;
    // this->inventory = kosong
}

Player::Player(string name){
    this->playerName = name;
    this->point = 0;
}

string Player::getPlayerName(){
    return this->playerName;
}

long int Player::getPlayerPoint(){
    return this->point;
}

void Player::showInventory(){
    for (vector<Card>::const_iterator i = this->inventory.begin(); i != this->inventory.end(); ++i){
        i->printCard();
    }
}