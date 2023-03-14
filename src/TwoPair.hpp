#ifndef __TWOPAIR_HPP__
#define __TWOPAIR_HPP__

#include "Valueable.hpp"
// #include "InventoryHolder.hpp"

using namespace std;

class TwoPair : public Value {
    private:
        InventoryHolder hold;
        map<string, InventoryHolder> mapcard;
    public:
        TwoPair(InventoryHolder hold, map<string, InventoryHolder> mapcard);
        ~TwoPair();
};

#endif