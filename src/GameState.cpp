#include "GameState.hpp"

long int GameState::prize = 64;
Deck* GameState::cardDeck = new Deck();
bool GameState::reverseTurn = false;
int GameState::turnStartFrom = 0;
deque<int> GameState::turn;
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
    long int prize = 64;
    bool reverseTurn = false;
    int turnStartFrom = 0;
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

Deck *GameState::getCardDeck() const
{
    return this->cardDeck;
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
    // temp deque for next round
    // deque<int> temp;
    for (int i = 0; i < playerCount; i++)
    {
    turn.push_back((i+turnStartFrom)%7);
    }
    // show current round
    cout << ":::::::::: Round " << this->round+1 << " ::::::::::"<<endl;
    cout << "current queue will be: ";
    for (auto i = turn.begin(); i != turn.end(); i++)
    {
        cout << "player " << *i + 1;
        if (i!=turn.end()-1){
            cout << "->";
        }
    }
    cout << endl;
    // input action from every players
    while (!turn.empty())
    {
        int nowPlaying = nextTurn();
        // temp.push_back(nowPlaying);
        // for (auto i = temp.begin(); i != temp.end(); i++)
        // {
        //     cout << "player " << *i + 1;
        //     if (i!=temp.end()-1){
        //         cout << "->";
        //     }
        // }
        // cout << endl;
        actionDo(this->players[nowPlaying].action());
    }
    // memasangkan turn untuk next round ke turn deque
    // turn = temp;
    turnStartFrom++;
    // deal kartu ke table kecuali round 6
    if (this->round == 5){
        *this->table += this->cardDeck->Draw();
        this->table->showInventory();
    }
}

void GameState::dealAbility()
{
    //shuffle abilities vector with seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(this->abilities.begin(), this->abilities.end(), std::default_random_engine(seed));
    //deal cards
    for (int i = 0; i < this->playerCount; i++)
    {
        // adding card to player inventory
        cout << this->players[i].getPlayerName() << " got " << abilities.back() << " ability" << endl;
        this->players[i].setPlayerAbility(abilities.back());
        abilities.pop_back();
    }
}

void GameState::actionDo(string input)
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

int GameState::nextTurn()
{
    int nextPlay;
    if (reverseTurn){
        nextPlay = this->turn.back();
        this->turn.pop_back();
    } else {
        nextPlay = this->turn.front();
        this->turn.pop_front();
    }
    return nextPlay;
}
