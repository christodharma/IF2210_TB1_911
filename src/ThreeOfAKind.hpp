#ifndef __THREEOFAKIND_HPP__
#define __THREEOFAKIND_HPP__

#include "Valueable.hpp"
// #include "InventoryHolder.hpp"

class ThreeOfAKind : public Value {
    public:
        ThreeOfAKind(map<string, InventoryHolder> mapcard);
        ~ThreeOfAKind();
};

#endif