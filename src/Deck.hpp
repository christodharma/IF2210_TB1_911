#ifndef __DECK_HPP__
#define __DECK_HPP__

#include "InventoryHolder.hpp"
#include "Card.hpp"
#include "Generics.hpp"

class Deck : virtual public InventoryHolder{
public:
    Deck();
    ~Deck();
    void ShuffleDeck();
    void DrawTo(vector<Card>&);
};

#endif