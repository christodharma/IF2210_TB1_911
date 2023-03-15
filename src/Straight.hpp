#ifndef __STRAIGHT_HPP__
#define __STRAIGHT_HPP__

#include "Valueable.hpp"
#include "InventoryHolder.hpp"

class Straight : public Value {
    private:
        InventoryHolder hold; // kombinasi kartu
        map<string, InventoryHolder> mapcard;
    public:
        Straight(InventoryHolder hold, map<string, InventoryHolder> mapcard);
        ~Straight();
        // InventoryHolder getCardStraight(map<string, InventoryHolder> mapcard);
};

#endif