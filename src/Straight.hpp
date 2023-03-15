#ifndef __STRAIGHT_HPP__
#define __STRAIGHT_HPP__

#include "Valueable.hpp"

class Straight : public Value {
    public:
        Straight(map<string, InventoryHolder> mapcard);
        ~Straight();
        // InventoryHolder getCardStraight(map<string, InventoryHolder> mapcard);
};

#endif