#include "GameState.hpp"

long int GameState::prize = 64;

GameState::GameState(Player* p, int n)
{
    cout << "Game State initiated" << endl;
    this->round = 0;
    this->prize = 64;
    this->players = p;
    this->playerCount = n;
    this->deck = new Deck();
    this->table = new Table();
    dealCards(2);
    cout << "Round " << this->round+1 << " started" << endl;
    cout << "Prize: " << this->prize << endl;
    // ask for player action(only double,next, or half);
    // dealTable();
    for (int i = 0; i < this->playerCount; i++)
    {
        this->players[i].showPlayerInfo();
    }
}
 
GameState::~GameState()
{
    delete this->deck;
    delete this->table;
}

int GameState::getRound() const
{
    return this->round;
}

long int GameState::getPrize() const
{
    return this->prize;
}

void GameState::nextRound()
{
    this->round = this->round + 1 % 6;
    cout << "Round " << this->round+1 << " started" << endl;
    cout << "Prize: " << this->prize << endl;
    if (this->round == 1)
    {
        //bagi ability
    } else if (this->round == 5){
        //show leaderboard
        //bagi prize untuk pemenang
        this->prize = 64;
    } else {
        //action diantara round 2-4
    }
}

void GameState::dealCards(int n)
{
    //shuffledeck
    this->deck->ShuffleDeck();
    //deal cards
    for (int i = 0; i < this->playerCount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // adding card to player inventory
            this->players[i]+=this->deck->DrawCard();
        }
    }
}

// void GameState::leaderboard()
// {
//     int* pos = new int[this->playerCount];
//     for (int i = 0; i < this->playerCount; i++)
//     {
//         pos[i] = i;
//     }
//     for (int i = 0; i < this->playerCount; i++)
//     {
//         int min = i;
//         for (int j = i+1; j < this->playerCount; j++)
//         {
//             if (this->players[j] < this->players[min])
//             {
//                 min = j;
//             }
//         }
//         int temp = pos[i];
//         pos[i] = pos[min];
//         pos[min] = temp;
//     }
// }
