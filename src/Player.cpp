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
    this->playerInventory = new CardInventory;
}

Player::Player(string name){
    this->playerName = name;
    this->point = 0;
    this->playerInventory = new CardInventory;
}

Player::~Player(){
    delete this->playerInventory;
}

string Player::getPlayerName()const {
    return this->playerName;
}

long int Player::getPlayerPoint()const {
    return this->point;
}

bool Player::isEmpty(){
    return this->playerInventory->isEmpty();
}

vector<Card>& Player::operator+=(Card& input){
    return *this->playerInventory += input;
}
vector<Card>& Player::operator-=(Card& input){
    return *this->playerInventory -= input;
}

vector<Card>& Player::operator+(Card& input){
    return *this->playerInventory + input;
}
vector<Card>& Player::operator-(Card& input){
    return *this->playerInventory - input;
}

void Player::showInventory(){
    cout << this->playerName << "'s Inventory:" << endl;
    if (this->isEmpty()){
        cout << "-" << endl;
    } else {
        this->playerInventory->showInventory();
    }
}

vector<Card>& Player::getInventory(){
    return this->playerInventory->getInventory();
}