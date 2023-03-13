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
    cout << "Player " << name << " initiated" << endl;
}

Player::Player(string name){
    this->playerName = name;
    this->point = 0;
    this->playerInventory = new CardInventory;
    cout << "Player " << name << " initiated" << endl;
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

void Player::showPlayerInfo()
{
}

void Player::inputAction()
{
    //input-input yang valid dimainkan oleh player
    string valid_inputs = "NEXTRE-ROLLDOUBLEQUADRUPLEHALFQUARTERREVERSESWAPCARDSWITCHABILITYLESS";
    string input;
    do
    {
        cin >> input;
        if (valid_inputs.find(input) == -1)
        {
            cout << "Invalid input, please try again" << endl;
        }
    } while (valid_inputs.find(input) == -1);
}

void Player::action_next()
{
    cout << "Giliran dilanjut ke pemain selanjutnya." << endl;
}


vector<Card> &Player::operator+=(Card &input)
{
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