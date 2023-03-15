#ifndef __DECK_HPP__
#define __DECK_HPP__

#include <iostream>
#include <fstream>
#include <string>
#include "InventoryHolder.hpp"
#include "Card.hpp"
#include "Generics.hpp"

using namespace std;

class Deck : virtual public InventoryHolder{
public:
    Deck();
    Deck(string);
    ~Deck();
    void ShuffleDeck();
    Card& Draw();
};

#endif