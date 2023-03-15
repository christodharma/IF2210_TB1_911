#ifndef __GAMESTATE_HPP__
#define __GAMESTATE_HPP__

#include "Deck.hpp"
#include "InventoryHolder.hpp"
#include "Card.hpp"
#include "Generics.hpp"
#include "Table.hpp"
#include "Player.hpp"
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <chrono>
using namespace std;

class GameState{
private:
    int round,playerCount;
    static vector<string> abilities;
    static deque<int> turn;
    static int turnStartFrom;
    static bool reverseTurn;
    long long int prize;
    Deck* cardDeck;
    Table* table;
    Player* players; //array of players buat nampung + urutan action
    //mungkin implement queue/deque buat round robin urutan action
public:
    //ctor dengan menerima player yang sudah dideklarasi dan n player
    GameState(Player*, int n);
    ~GameState();

    //getter
    int getRound() const;
    long int getPrize() const;
    Deck* getCardDeck();
    //setter
    void setPrize(long int);

    //gamestate methods
    void nextRound();
    void playRound();
    void dealCards(int);
    void dealAbility();
    void actionDo(string);
    int nextTurn();
};

#endif