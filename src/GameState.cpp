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

Player *GameState::getPlayers() const
{
    return this->players;
}

Player& GameState::getPlayer(int i) const
{
    return this->players[i];
}

void GameState::printPlayers()
{
    for (int i = 0; i < playerCount; i++)
    {
        cout << "   " << i+1 << ". " << this->getPlayer(i).getPlayerName() << endl;
    }
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
        actionDo(this->players[nowPlaying].action(), &(this->players[nowPlaying]));
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

void GameState::actionDo(string input, Player* p)
{
    string abilityInput = "RE-ROLLQUADRUPLEQUARTERREVERSESWAPCARDSWITCHABILITYLESS";
    if (input == "NEXT"){
        //do nothing
        cout << "Giliran dilanjut ke pemain selanjutnya." << endl;
    } else if (input == "DOUBLE"){
        cout << p->getPlayerName() << " melakukan DOUBLE! " << endl;
        cout << "Poin hadiah naik dari " << this->prize << " menjadi " << this->prize*2 << "!" << endl;
        this->prize *= 2;
    } else if (input == "HALF"){
        cout << p->getPlayerName() << " melakukan HALF! " << endl;
        cout << "Poin hadiah turun dari " << this->prize << " menjadi " << this->prize/2 << "!" << endl;
        this->prize /= 2;
    } else if (input == "QUADRUPLE") {
        if (p->getPlayerAbility()->showAbility() == "QUADRUPLE") {
            cout << p->getPlayerName() << " melakukan QUADRUPLE! " << endl;
            cout << "Poin hadiah naik dari " << this->prize << " menjadi " << this->prize*4 << "!" << endl;
            this->prize *= 4;
        } else {
            p->getPlayerAbility()->noAbility(input);
            // actionDo(this->players[this->nextTurn()].action(), &(this->players[this->nextTurn()]));
        }
    } else if (input == "QUARTER") {
        if (p->getPlayerAbility()->showAbility() == "QUARTER") {
            cout << p->getPlayerName() << " melakukan QUARTER! " << endl;
            cout << "Poin hadiah turun dari " << this->prize << " menjadi " << this->prize/4 << "!" << endl;
            this->prize /= 4;
        } else {
            p->getPlayerAbility()->noAbility(input);
            // actionDo(this->players[this->nextTurn()].action(), &(this->players[this->nextTurn()]));
        }
    } else if (input == "RE-ROLL") {
        if (p->getPlayerAbility()->showAbility() == "RE-ROLL") {
            cout << "Kamu mendapatkan 2 kartu baru yaitu: " << endl;
            p->getInventory().clear();
            *p += this->cardDeck->Draw();
            *p += this->cardDeck->Draw();
            p->showInventory();
        } else {
            p->getPlayerAbility()->noAbility(input);
            // actionDo(this->players[this->nextTurn()].action(), &(this->players[this->nextTurn()]));
        }
    } else if (input == "SWITCH") {
        if (p->getPlayerAbility()->showAbility() == "SWITCH") {
            cout << p->getPlayerName() << " melakukan SWITCH!" << endl;
            cout << "Kartumu sekarang adalah: " << endl;
            p->showInventory();
            cout << "Silakan pilih pemain yang kartunya ingin Anda tukar:" << endl;
            for(int i = 0; i < this->playerCount; i++) {
                if (this->players[i].getPlayerName() != p->getPlayerName()) {
                    cout << "   " << i+1 << ". " << this->players[i].getPlayerName() << endl;
                }
            }
            int input;
            cin >> input;
            vector<Card> temp = p->getInventory();
            p->setPlayerInventory(this->getPlayer(input-1).getInventory());
            this->getPlayer(input-1).setPlayerInventory(temp);
            cout << "Kedua kartu " << p->getPlayerName() << " telah ditukar dengan " << this->getPlayer(input-1).getPlayerName() << endl;
            cout << "Kartumu sekarang adalah: " << endl;
            p->showInventory();
        } else {
            p->getPlayerAbility()->noAbility(input);
            // actionDo(this->players[this->nextTurn()].action(), &(this->players[this->nextTurn()]));
        }
    } else if (input == "SWAP") {
        if (p->getPlayerAbility()->showAbility() == "SWAP") {
            cout << p->getPlayerName() << " melakukan SWAP!" << endl;
            cout << "Silakan pilih pemain yang kartunya ingin Anda tukar:" << endl;
            for (int i = 0; i < this->playerCount; i++) {
                if (this->players[i].getPlayerName() != p->getPlayerName()) {
                    cout << "   " << i+1 << ". " << this->players[i].getPlayerName() << endl;
                }
            }
            int p1, p2, c1, c2;
            cin >> p1;
            cout << "Silakan pilih pemain lain yang kartunya ingin Anda tukar:" << endl;
            for (int i = 0; i < this->playerCount; i++) {
                if (this->players[i].getPlayerName() != p->getPlayerName() && this->players[i].getPlayerName() != this->getPlayer(p1-1).getPlayerName()) {
                    cout << "   " << i+1 << ". " << this->players[i].getPlayerName() << endl;
                }
            }
            cin >> p2;
            cout << "Silakan pilih kartu kanan/kiri " << this->getPlayer(p1-1).getPlayerName() << endl;
            cout << "   1. Kiri" << endl;
            cout << "   2. Kanan" << endl;
            cin >> c1;
            cout << "Silakan pilih kartu kanan/kiri " << this->getPlayer(p2-1).getPlayerName() << endl;
            cout << "   1. Kiri" << endl;
            cout << "   2. Kanan" << endl;
            cin >> c2;
            Card temp = this->getPlayer(p1-1).getInventory()[c1-1];
            this->getPlayer(p1-1).getInventory()[c1-1] = this->getPlayer(p2-1).getInventory()[c2-1];
            this->getPlayer(p2-1).getInventory()[c2-1] = temp;
            this->getPlayer(p1-1).showInventory();
            this->getPlayer(p2-1).showInventory();
        } else {
            p->getPlayerAbility()->noAbility(input);
            // actionDo(this->players[this->nextTurn()].action(), &(this->players[this->nextTurn()]));
        }
    }

    else if (abilityInput.find(input)!=-1){
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
