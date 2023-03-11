#include "GameState.hpp"

long int GameState::prize = 64;
bool GameState::isOngoing = true;

GameState::GameState()
{
    cout << "Game State initiated" << endl;
    this->round = 0;
    this->table = new CardInventory;
}

GameState::~GameState()
{
    delete this->table;
    // delete this->deck;
}

int GameState::getRound() const
{
    return this->round;
}
//initiate Cards in the game into an array of cards (deck)
void GameState::InitiateDeck()
{
    int i = 0;
    for (int j = 0; j < 4; j++)
    {
        for (int k = 0; k < 13; k++)
        {
            if (j==0)
            {
                this->deck[i] = new Card('h', k+1);
                i++;
            } else if (j==1){
                this->deck[i] = new Card('b', k+1);
                i++;
            } else if (j==2){
                this->deck[i] = new Card('k', k+1);
                i++;
            } else if (j==3){
                this->deck[i] = new Card('m', k+1);
                i++;
            }
        }
    }
    cout << "Deck of " << i << " Cards initiated" << endl;
}

long int GameState::getPrize() const
{
    return this->prize;
}

void GameState::NextRound()
{
    this->round++;
    //this->prize = this->prize; //do something with the prize according to player actions
    if (this->round == 6)
    {
        this->isOngoing = false;
    }
}

bool GameState::isGameOngoing()
{
    return this->isOngoing;
}

void GameState::showInventory()
{
    this->table->showInventory();
}

bool GameState::isEmpty()
{
    return this->table->isEmpty();
}
vector<Card>& GameState::getInventory()
{
    return this->table->getInventory();
}
vector<Card>& GameState::operator+=(Card& input)
{
    return *this->table += input;
}
vector<Card>& GameState::operator-=(Card& input)
{
    return *this->table -= input;
}
vector<Card>& GameState::operator+(Card& input)
{
    return *this->table + input;
}
vector<Card>& GameState::operator-(Card& input)
{
    return *this->table - input;
}