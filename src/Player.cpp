#include "Player.hpp"

Player::Player()
{
    string name;
    cout<<"Please insert player name: ";
    cin >> name;
    this->playerName = name;
    this->point = 0;
    this->ability = new Ability;
    this->hand = new Inventory;
    cout << "Player " << name << " initiated" << endl;
}

Player::Player(string name)
{
    this->playerName = name;
    this->point = 0;
    this->ability = new Ability;
    this->hand = new Inventory;
    cout << "Player " << name << " initiated" << endl;
}

Player::~Player(){
    delete this->ability;
    delete this->hand;
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
        delete this->ability;
        this->ability = new ReRoll();
    } else if (input == "QUADRUPLE")
    {
        delete this->ability;
        this->ability = new Quadruple();
    } else if (input == "QUARTER")
    {
        delete this->ability;
        this->ability = new Quarter();
    } else if (input == "REVERSE")
    {
        delete this->ability;
        this->ability = new ReverseDirection();
    } else if (input == "SWAPCARD")
    {
        delete this->ability;
        this->ability = new SwapCard();
    } else if (input == "SWITCH")
    {
        delete this->ability;
        this->ability = new Switch();
    } else if (input == "ABILITYLESS")
    {
        delete this->ability;
        this->ability = new Abilityless();
    }
}

void Player::initializeHand()
{
    this->hand = new Inventory;
}

void Player::clearHand()
{
    delete this->hand;
}

void Player::showPlayerInfo() const
{
    cout << "==========\tPlayer Info\t==========" <<endl;
    cout << "Player name: "<<this->getPlayerName() << endl;
    cout << "Player point: "<<this->getPlayerPoint() << endl;
    cout << "Player ability: "<<this->ability->showAbility() << endl; // error
    cout << "Player inventory: " << endl;
    this->hand->showInventory();
}

string Player::action()
{
    //input-input yang valid dimainkan oleh player
    string valid_inputs = "NEXTRE-ROLLDOUBLEQUADRUPLEHALFQUARTERREVERSESWAPCARDSWITCHABILITYLESS";
    string input;
    do
    {
        cout << "Input your action, "<<this->getPlayerName()<<"! ";
        cin >> input;
        if (valid_inputs.find(input) == -1)
        {
            cout << "Invalid input, please try again" << endl;
        } else {

            break;
        }
    } while (valid_inputs.find(input) == -1);
    return input;
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

bool Player::isEmpty()
{
    return this->hand->isEmpty();
}

void Player::showInventory() const
{
    this->hand->showInventory();
}

vector<Card> &Player::getInventory()
{
    return this->hand->getInventory();
}

vector<Card> &Player::operator+=(Card &input )
{
    return this->hand->operator+=(input);
}

vector<Card> &Player::operator-=(Card &input)
{
    return this->hand->operator-=(input);
}

vector<Card> &Player::operator+(Card &input)
{
    return this->hand->operator+(input);
}

vector<Card> &Player::operator-(Card &input)
{
    return this->hand->operator-(input);
}

vector<Card> &Player::operator=(const vector<Card> &copy)
{
    return this->hand->operator=(copy);
}