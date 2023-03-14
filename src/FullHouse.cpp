#include "FullHouse.hpp"

FullHouse::FullHouse(double i) : Value(0) {
    double maksFlush = 14.58;
    this->value = 3*i*0.1 + maksFlush;
}

FullHouse::~FullHouse() {
}