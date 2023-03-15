#ifndef __STRAIGHTFLUSH_HPP__
#define __STRAIGHTFLUSH_HPP__

#include <iostream>
#include <string>
#include "Valueable.hpp"
#include "InventoryHolder.hpp"

using namespace std;

class StraightFlush : public Value {
    public:
        StraightFlush(map<string, InventoryHolder>);
        ~StraightFlush();
        // double getValue();
};

#endif