#ifndef __DECK_HPP__
#define __DECK_HPP__

#include "InventoryHolder.hpp"
#include "Inventory.hpp"
#include "Card.hpp"
#include "Generics.hpp"
#include <vector>

class Deck {
protected:
    vector<Card> _deck;
public:
    Deck();
    ~Deck();
    void InitializeDeck();
    void ShuffleDeck();
    void DrawTo(vector<Card>&);
    void showInventory() const;
    vector<Card>& getDeck();
};

#endif