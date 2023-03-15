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
    static long int prize;
    static Deck* cardDeck;
    static vector<string> abilities;
    static deque<int> turn;
    static int turnStartFrom;
    static bool reverseTurn;
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
    Deck* getCardDeck() const;
    Player* getPlayers() const;
    Player& getPlayer(int) const;
    InventoryHolder& getTable() const;
    //setter
    void setPrize(long int);

    //gamestate methods
    void nextRound();
    void playRound();
    void dealAbility();
    void actionDo(string, Player*);
    int nextTurn();
    void printPlayers();
    // void leaderboard();
    // void nextTurn();

    //inheritance methods
    //Inventory holder inheritance
    // void showInventory();
    // bool isEmpty(); 
    // vector<Card>& getInventory();
    // vector<Card>& operator+=(Card&);
    // vector<Card>& operator-=(Card&);
    // vector<Card>& operator+(Card&);
    // vector<Card>& operator-(Card&);
};

#endif