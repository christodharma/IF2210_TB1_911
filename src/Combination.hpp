#ifndef __COMBINATION_HPP__
#define __COMBINATION_HPP__

#include <map>
#include "Valueable.hpp"
#include "Card.hpp"
#include "InventoryHolder.hpp"

class Combination : Valueable{
private:
    Card* combo;
public:
    Combination(vector<Card> table, vector<Card> inventory);
    ~Combination();
    double getValue() const;
};

#endif