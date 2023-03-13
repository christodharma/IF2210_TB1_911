#ifndef __FOUROFAKIND_HPP__
#define __FOUROFAKIND_HPP__

#include "Valueable.hpp"

class FourOfAKind : public Value {
    public:
        FourOfAKind(CardInventory hold, map<string, CardInventory> mapcard);
        ~FourOfAKind();
};

#endif