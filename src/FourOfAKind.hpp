#ifndef __FOUROFAKIND_HPP__
#define __FOUROFAKIND_HPP__

#include "Valueable.hpp"

class FourOfAKind : public Value {
    public:
        FourOfAKind(InventoryHolder hold, map<string, InventoryHolder> mapcard);
        ~FourOfAKind();
};

#endif