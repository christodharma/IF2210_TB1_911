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

class GameState : public Deck, public Table{
private:
    static deque<int> turn;
    static int turnStartFrom;
    static bool reverseTurn;
    int round,playerCount;
    vector<string> abilities;
    long long int prize;
    Player* players;
public:
    //ctor dengan menerima player yang sudah dideklarasi dan n player
    GameState(Player*&, int n);
    ~GameState();

    //getter
    int getRound() const;
    long int getPrize() const;
    //setter
    void setPrize(long int);

    //gamestate methods
    void nextRound();
    void playRound();
    void dealCards(Player& who, int cardCount);
    void dealAbility();
    void actionDo(string);
    int nextTurn();

    /*inheritance methods*/
    void showInventory() const override;
    // bool isEmpty() override;
    //Deck
    vector<Card>& getInventory(Deck);
    void showInventory(Deck) const;
    // void ShuffleDeck();
    // void DrawTo(vector<Card>&);
    // vector<Card>& operator+=(Card&) ;
    // vector<Card>& operator-=(Card&) ;
    // vector<Card>& operator+(Card&) ;
    // vector<Card>& operator-(Card&) ;
    // vector<Card>& operator=(const vector<Card>&) ;
    //Table
    vector<Card>& getInventory(Table);
    void showInventory(Table) const;
};

#endif