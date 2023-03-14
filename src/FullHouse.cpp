#include "FullHouse.hpp"

FullHouse::FullHouse(double i) : Value(0) {
    int maksFlush = 95;
    this->value = 3*i + maksFlush;
}

FullHouse::~FullHouse() {
}