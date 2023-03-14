#include "FourOfAKind.hpp"

FourOfAKind::FourOfAKind(double v) : Value(0) {
    int maksFlush = 95;
    this->value = 4*v + maksFlush;
}

FourOfAKind::~FourOfAKind() {
}