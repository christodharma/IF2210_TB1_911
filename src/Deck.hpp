#ifndef __DECK_HPP__
#define __DECK_HPP__

#include "InventoryHolder.hpp"
#include "Inventory.hpp"
#include "Card.hpp"
#include "Generics.hpp"

class Deck : virtual public InventoryHolder{
private:
    InventoryHolder* _deck;
public:
    Deck();
    ~Deck();
    void ShuffleDeck();
    void DrawTo(vector<Card>&);
    bool isEmpty();
    void showInventory() const;
    vector<Card>& getInventory();
    // vector<Card>& operator+=(Card&) ;
    // vector<Card>& operator-=(Card&) ;
    // vector<Card>& operator+(Card&) ;
    // vector<Card>& operator-(Card&) ;
    vector<Card>& operator=(const vector<Card>&) ;
};

#endif