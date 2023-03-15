#ifndef __PAIR_HPP__
#define __PAIR_HPP__

#include <iostream>
#include <string>
#include "Valueable.hpp"
#include "InventoryHolder.hpp"

using namespace std;

class Pair : public Value {
    public:
        Pair(map<string, InventoryHolder>);
        ~Pair();
};

#endif