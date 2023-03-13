#ifndef __DECK_HPP__
#define __DECK_HPP__

#include "InventoryHolder.hpp"
#include "Card.hpp"
#include <algorithm>
#include <random>

class Deck : virtual public InventoryHolder{
public:
    Deck();
    ~Deck();
    void InitiateDeck();
    void ShuffleDeck();
    Card& DrawCard();
};

#endif