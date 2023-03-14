#include "GameState.hpp"

long int GameState::prize = 64;
Deck* GameState::cardDeck = new Deck();
vector<string> GameState::abilities =
{
    "RE-ROLL",
    "QUADRUPLE",
    "QUARTER",
    "REVERSE",
    "SWAPCARD",
    "SWITCH",
    "ABILITYLESS"
};

GameState::GameState(Player* p, int n)
{
    this->round = 0;
    this->prize = 64;
    this->players = p;
    this->playerCount = n;
    this->table = new Table();
    cout << "Game State initiated" << endl;
}
 
GameState::~GameState()
{
    delete cardDeck;
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

void GameState::setPrize(long int input)
{
    this->prize = input;
}

void GameState::nextRound(){
    this->round = this->round + 1 % 6;
}

void GameState::playRound()
{
    // show current round
    cout << ":::::::::: Round " << this->round+1 << " ::::::::::"<<endl;
    // input action from every players
    for (int i = 0; i < playerCount; i++)
    {
        cout << "Player " << this->players[i].getPlayerName() << " turn" << endl;
        this->actionDo(this->players[i].action());
    }
    // deal kartu ke table
    if (this->round == 5){
        *this->table += this->cardDeck->Draw();
        this->table->showInventory();
    }
}

void GameState::dealCards(int n)
{
    //shuffledeck
    this->cardDeck->ShuffleDeck();
    //deal cards
    for (int i = 0; i < this->playerCount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // adding card to player inventory
            this->players[i]+=this->cardDeck->Draw();
        }
    }    
}

void GameState::dealAbility()
{
    //shuffle abilities vector with seed
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(this->abilities.begin(), this->abilities.end(), default_random_engine(seed));
    //deal cards
    for (int i = 0; i < this->playerCount; i++)
    {
        // adding card to player inventory
        cout << this->players[i].getPlayerName() << " got " << abilities.back() << " ability" << endl;
        this->players[i].setPlayerAbility(abilities.back());
        abilities.pop_back();
    }
}

void GameState::actionDo(char* input)
{
    string abilityInput = "RE-ROLLQUADRUPLEQUARTERREVERSESWAPCARDSWITCHABILITYLESS";
    if (input == "NEXT"){
        //do nothing
    } else if (input == "DOUBLE"){
        cout << "prize doubled" << endl;
        this->prize *= 2;
    } else if (input == "HALF"){
        cout << "prize halved" << endl;
        this->prize /= 2;
    } else if (abilityInput.find(input)!=-1){
        //input ability
        cout << input << "invocation" << endl;
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
