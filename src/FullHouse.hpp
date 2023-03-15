#ifndef __FULLHOUSE_HPP__
#define __FULLHOUSE_HPP__

#include "Valueable.hpp"
#include <iostream>
using namespace std;

class FullHouse : public Value {
    public:
        FullHouse(double i);
        ~FullHouse();
};

#endif