#ifndef __GAMESTATE_HPP__
#define __GAMESTATE_HPP__

#include "InventoryHolder.hpp"
#include "Card.hpp"

class GameState: public InventoryHolder{
private:
    InventoryHolder* table;
    Card* deck[52];
    int round;
    static long int prize;
    static bool isOngoing;
    //Player* players[7]; //array of players buat nampung + urutan action
    //mungkin implement queue/deque buat round robin urutan action
public:
    GameState();
    ~GameState();
    void InitiateDeck();
    void NextRound();
    int getRound() const;
    long int getPrize() const;
    bool isGameOngoing();

    //inheritance methods
    void showInventory();
    bool isEmpty();
    vector<Card>& getInventory();
    vector<Card>& operator+=(Card&);
    vector<Card>& operator-=(Card&);
    vector<Card>& operator+(Card&);
    vector<Card>& operator-(Card&);
};

#endif