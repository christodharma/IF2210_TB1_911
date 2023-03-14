#ifndef __THREEOFAKIND_HPP__
#define __THREEOFAKIND_HPP__

#include "Valueable.hpp"
// #include "InventoryHolder.hpp"

class ThreeOfAKind : public Value {
    private:
        InventoryHolder hold;
        map<string, InventoryHolder> mapcard;
    public:
        ThreeOfAKind(InventoryHolder hold, map<string, InventoryHolder> mapcard);
        ~ThreeOfAKind();
};

#endif