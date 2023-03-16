#ifndef __FOUROFAKIND_HPP__
#define __FOUROFAKIND_HPP__

#include "Valueable.hpp"
#include <iostream>
using namespace std;

#include "Valueable.hpp"

class FourOfAKind : public Value {
    public:
        FourOfAKind(double v);
        ~FourOfAKind();
};

#endif