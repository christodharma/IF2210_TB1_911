#ifndef __DECK_HPP__
#define __DECK_HPP__

#include "InventoryHolder.hpp"
#include "Card.hpp"
#include "randomdependency.hpp"

template<class T>
class Deck : virtual public InventoryHolder<T>{
public:
    Deck();
    ~Deck();
    void ShuffleDeck();
    T& Draw();
};

#endif