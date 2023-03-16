#include "GameState.hpp"

bool GameState::reverseTurn = false;
int GameState::turnStartFrom = 0;
deque<int> GameState::turn = {0,1,2,3,4,5,6};
GameState::GameState(Player*& p, int n)
{
    this->round = 0;
    this->prize = 64;
    this->players = p;
    this->playerCount = n;
    this->table = new Table();
    cout << "Pilih input Deck: " << endl;
    cout << "1. Random" << endl;
    cout << "2. Custom dari file" << endl;
    cout << "Masukkan pilihan: ";
    int input;
    cin >> input;
    if (input == 1){
        this->cardDeck = new Deck();
    } else if (input == 2){
        string filename;
        cout << "Masukkan nama file: ";
        cin >> filename;
        this->cardDeck = new Deck(filename);
    }
    this->prize = 64;
    this->abilities =
    {
    "RE-ROLL",
    "QUADRUPLE",
    "QUARTER",
    "REVERSE",
    "SWAPCARD",
    "SWITCH",
    "ABILITYLESS"
    };
    cout << "Game State initiated" << endl;
    cout    <<  "::::::::::\t ROUND \t ::::::::::"          << endl 
            <<  "::::::::::\t   " << this->round+1 << "\t ::::::::::"<<endl
            <<  "::::::::::\t PRIZE \t ::::::::::"<< endl <<
                "::::::::::\t   " << this->prize << "\t ::::::::::"<<endl;
}
 
GameState::~GameState()
{
    long int prize = 64;
    bool reverseTurn = false;
    int turnStartFrom = 0;
    delete this->cardDeck;
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

InventoryHolder& GameState::getTable() const
{
    return *this->table;
}

void GameState::printPlayers()
{
    for (int i = 0; i < playerCount; i++)
    {
        cout << "   " << i+1 << ". " << this->getPlayer(i).getPlayerName() << endl;
    }
}

void GameState::nextRound(){
    this->round = this->round + 1;
}

void GameState::playRound()
{   if (reverseTurn) {reverseTurn = false;} //reset reverse turn
    deque<int> temp;
    // set start from turnStartFrom
    // show current round
    cout << ":::::::::: Round " << this->round+1 << " ::::::::::"<<endl;
    cout << "current queue will be: ";
    for (int i=0; i<turn.size(); i++)
    {
        cout << "<" << this->getPlayer(turn.at((turnStartFrom+ i) %7)).getPlayerName() << ">";
        if (i!=turn.size()-1){
            cout << " ";
        }
    }
    cout << endl;
    int j = 1;
    // input action from every players
    for (int i=0; i<7; i++)
    {   
        int nowPlaying;
        if (reverseTurn){
            nowPlaying = turnStartFrom - j;
            if (nowPlaying < 0) {
                nowPlaying = nowPlaying+7;
                nowPlaying = this->turn.at(nowPlaying);
            } else {
                nowPlaying = this->turn.at(nowPlaying);
            }
            j++;
            temp.push_back(nowPlaying);
        } else {
            nowPlaying = this->turn.at((turnStartFrom+i)%7);
            temp.push_front(nowPlaying);
        }
        actionDo(this->players[nowPlaying].action(), &(this->players[nowPlaying]));
    }
    // memasangkan turn untuk next round ke turn deque
    // turn = temp;
    turnStartFrom = (turnStartFrom+1)%7;
    // deal kartu ke table kecuali round 6
    if (this->round < 6){
        // how many cards in the deck
        // cout << "Deck count:" << this->cardDeck->getInventory().size() << endl;
        cardDeck->DrawTo(this->table->getInventory());
        this->table->showTable();
    }

    if (reverseTurn) {
        turn.clear();
        int popped = temp.front();
        temp.pop_front();
        temp.push_back(popped);
        turn = temp;
        turnStartFrom = 0;
    }
}

void GameState::gameEnd(Player& winner)
{
    cout << ":::::::::: Game End ::::::::::"<<endl;
    winner.setPlayerPoint(winner.getPlayerPoint() + this->prize);
    cout << "Player " << winner.getPlayerName() << " won " << this->prize << " points" << endl;
    this->prize = 64; //reset prize
    for (int i = 0; i < playerCount; i++)
    {
        players[i].showPlayerInfo();
        players[i].getInventory().clear();
    }
    this->table->getInventory().clear();
}

void GameState::dealCards(int who, int howMany)
{
    // shuffle deck
    this->cardDeck->ShuffleDeck();
    //dealing card by calling drawCard() from players
    // adding card to player inventory
    Deck*& src = this->cardDeck;
    this->players[who].drawCards(howMany, src);
    this->players[who].showPlayerInfo();
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
        if (this->getPrize() > 1) {
            cout << "Poin hadiah turun dari " << this->prize << " menjadi " << this->prize/2 << "!" << endl;
            this->prize /= 2;
        } else {
            cout << "Sayangnya poin hadiah suda bernilai 1. Poin hadiah tidak berubah.." << endl;
        }
        
    } else if (input == "QUADRUPLE") {
        if (p->getPlayerAbility()->showAbility() == "QUADRUPLE" && !p->getPlayerAbility()->isDisabled() && !p->getPlayerAbility()->isUsed()) {
            cout << p->getPlayerName() << " melakukan QUADRUPLE! " << endl;
            p->getPlayerAbility()->ability(input);
            cout << "Poin hadiah naik dari " << this->prize << " menjadi " << this->prize*4 << "!" << endl;
            this->prize *= 4;
            p->getPlayerAbility()->setUsed(true);
        } else {
            p->getPlayerAbility()->noAbility(input);
            // actionDo(this->players[this->nextTurn()].action(), &(this->players[this->nextTurn()]));
        }

    } else if (input == "QUARTER") {
        if (p->getPlayerAbility()->showAbility() == "QUARTER" && !p->getPlayerAbility()->isDisabled() && !p->getPlayerAbility()->isUsed()) {
            cout << p->getPlayerName() << " melakukan QUARTER! " << endl;
            p->getPlayerAbility()->ability(input);
            cout << "Poin hadiah turun dari " << this->prize << " menjadi " << this->prize/4 << "!" << endl;
            this->prize /= 4;
            p->getPlayerAbility()->setUsed(true);
        } else {
            p->getPlayerAbility()->noAbility(input);
            // actionDo(this->players[this->nextTurn()].action(), &(this->players[this->nextTurn()]));
        }
    } else if (input == "RE-ROLL") {
        if (p->getPlayerAbility()->showAbility() == "RE-ROLL" && !p->getPlayerAbility()->isDisabled() && !p->getPlayerAbility()->isUsed()) {
            p->getPlayerAbility()->ability(input);
            cout << "Kamu mendapatkan 2 kartu baru yaitu: " << endl;
            p->getInventory().clear();
            this->cardDeck->DrawTo(p->getInventory());
            this->cardDeck->DrawTo(p->getInventory());
            p->showInventory();
            p->getPlayerAbility()->setUsed(true);
        } else {
            p->getPlayerAbility()->noAbility(input);
            // actionDo(this->players[this->nextTurn()].action(), &(this->players[this->nextTurn()]));
        }

    } else if (input == "SWITCH") {
        if (p->getPlayerAbility()->showAbility() == "SWITCH" && !p->getPlayerAbility()->isDisabled() && !p->getPlayerAbility()->isUsed()) {
            cout << p->getPlayerName() << " melakukan SWITCH!" << endl;
            p->getPlayerAbility()->ability(input);
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
            p->getPlayerAbility()->setUsed(true);
        } else {
            p->getPlayerAbility()->noAbility(input);
            // actionDo(this->players[this->nextTurn()].action(), &(this->players[this->nextTurn()]));
        }

    } else if (input == "SWAPCARD") {
        if (p->getPlayerAbility()->showAbility() == "SWAPCARD" && !p->getPlayerAbility()->isDisabled() && !p->getPlayerAbility()->isUsed()) {
            cout << p->getPlayerName() << " melakukan SWAPCARD!" << endl;
            p->getPlayerAbility()->ability(input);
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

            p->getPlayerAbility()->setUsed(true);

        } else {
            p->getPlayerAbility()->noAbility(input);
            // actionDo(this->players[this->nextTurn()].action(), &(this->players[this->nextTurn()]));
        }
    }

    else if (input == "REVERSE") {
        if (p->getPlayerAbility()->showAbility() == "REVERSE"  && !p->getPlayerAbility()->isDisabled() && !p->getPlayerAbility()->isUsed()) {
            cout << p->getPlayerName() << " melakukan REVERSE!" << endl;
            p->getPlayerAbility()->ability(input);
            p->getPlayerAbility()->setUsed(true);
            this->reverseTurn = true;
        }
        else {
            p->getPlayerAbility()->noAbility(input);
        }
    }

    else if (input == "ABILITYLESS") {
        if (p->getPlayerAbility()->showAbility() == "ABILITYLESS") {
            int countPAb = 0;
            for (int i=0; i<this->playerCount; i++) {
                if (p->getPlayerName() != this->getPlayer(i).getPlayerName() && this->getPlayer(i).doesHaveAbility()) {
                    countPAb++;
                }
            }

            if (countPAb > 0) {
                cout << p->getPlayerName() << " akan mematikan kartu ability lawan!" << endl;
                p->getPlayerAbility()->ability(input);
                cout << "Silakan pilih pemain yang kartu ability-nya ingin dimatikan:" << endl;
                for (int i=0; i<this->playerCount; i++) {
                    if (p->getPlayerName() != this->players[i].getPlayerName()) {
                        cout << "   " << i+1 << ". " << this->players[i].getPlayerName() << endl;
                    }
                }
                int pinput;
                cin >> pinput;
                if (this->getPlayer(pinput-1).doesHaveAbility() && !this->getPlayer(pinput-1).getPlayerAbility()->isUsed()) {
                    this->getPlayer(pinput-1).getPlayerAbility()->setDisabled(true);
                    cout << "Kartu ability " << this->getPlayer(pinput-1).getPlayerName() << " telah dimatikan." << endl;
                    p->getPlayerAbility()->setUsed(true);
                } else if (this->getPlayer(pinput-1).getPlayerAbility()->isUsed()) {
                    cout << "Kartu ability " << this->getPlayer(pinput-1).getPlayerName() << " telah dipakai sebelumnya. Yah, sayang penggunaan kartu ini sia-sia" << endl;
                }
                
            } else {
                cout << "Eitss, ternyata semua pemain sudah memakai kartu kemampuan. Yah, penggunaan kartu ini sia-sia" << endl;
            }
            p->getPlayerAbility()->setUsed(true);
        } else {
            p->getPlayerAbility()->noAbility(input);
        }
    }

    else if (abilityInput.find(input)!=-1){
        //input ability
        cout << input << "invocation" << endl;
    }
}

