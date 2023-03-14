#ifndef __DECK_HPP__
#define __DECK_HPP__

#include "InventoryHolder.hpp"
#include "Card.hpp"
#include "randomdependency.hpp"

class Deck : virtual public InventoryHolder{
public:
    Deck();
    ~Deck();
    void ShuffleDeck();
    Card& Draw();
};

#endif