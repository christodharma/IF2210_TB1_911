#ifndef __HIGHCARD_HPP__
#define __HIGHCARD_HPP__

#include <iostream>
#include <string>
#include "Valueable.hpp"
#include "InventoryHolder.hpp"

using namespace std;

class HighCard : public Value {
    public:
        HighCard(map<string, InventoryHolder>);
        ~HighCard();
        double getValue();
};

#endif