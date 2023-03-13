#include "InventoryHolder.hpp"
#include "Card.hpp"
#include "Player.hpp"
#include <iostream>
using namespace std;

Player::Player() : InventoryHolder()
{
    string name;
    cout<<"Please insert player name: ";
    cin >> name;
    this->playerName = name;
    this->point = 0;
    cout << "Player " << name << " initiated" << endl;
}

Player::Player(string name) : InventoryHolder()
{
    this->playerName = name;
    this->point = 0;
    cout << "Player " << name << " initiated" << endl;
}

Player::~Player(){
}

string Player::getPlayerName()const {
    return this->playerName;
}

long int Player::getPlayerPoint()const {
    return this->point;
}

void Player::setPlayerPoint(long int input)
{
    this->point = input;
}

void Player::showPlayerInfo() const
{
    cout << "Player name: "<<this->getPlayerName() << endl;
    cout << "Player point: "<<this->getPlayerPoint() << endl;
    this->showInventory();
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


bool Player::operator>(Player& other)
{
    return this->getPlayerPoint() > other.getPlayerPoint();
}
bool Player::operator<(Player& other)
{
    return this->getPlayerPoint() < other.getPlayerPoint();
}
bool Player::operator==(Player& other)
{
    return this->getPlayerPoint() == other.getPlayerPoint();
}