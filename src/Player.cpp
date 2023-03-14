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

void Player::setPlayerAbility(string input)
{
    if (input == "RE-ROLL")
    {
        this->ability = new ReRoll();
    } else if (input == "QUADRUPLE")
    {
        this->ability = new Quadruple();
    } else if (input == "QUARTER")
    {
        this->ability = new Quarter();
    } else if (input == "REVERSE")
    {
        this->ability = new ReverseDirection();
    } else if (input == "SWAPCARD")
    {
        this->ability = new SwapCard();
    } else if (input == "SWITCH")
    {
        this->ability = new Switch();
    } else if (input == "ABILITYLESS")
    {
        this->ability = new Abilityless();
    }
}

void Player::showPlayerInfo() const
{
    cout << "Player name: "<<this->getPlayerName() << endl;
    cout << "Player point: "<<this->getPlayerPoint() << endl;
    cout << "Player ability: "<<this->ability->showAbility() << endl;
    this->showInventory();
}

char* Player::action()
{
    //input-input yang valid dimainkan oleh player
    string valid_inputs = "NEXTRE-ROLLDOUBLEQUADRUPLEHALFQUARTERREVERSESWAPCARDSWITCHABILITYLESS";
    char* input;
    do
    {
        cin >> input;
        if (valid_inputs.find(input) == -1)
        {
            cout << "Invalid input, please try again" << endl;
        } else {
            return input;
        }
    } while (valid_inputs.find(input) == -1);
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