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
#include "randomdependency.hpp"
using namespace std;

class GameState{
private:
    int round,playerCount;
    static long int prize;
    Deck<Card>* cardDeck;
    Deck<string>* abilityDeck;
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
    //setter

    //gamestate methods
    void nextRound();
    void dealCards(int);
    void dealAbility();
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