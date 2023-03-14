#include "FourOfAKind.hpp"

FourOfAKind::FourOfAKind(double v) : Value(0) {
    double maksFH = 18.48;
    this->value = 4*v*0.1 + maksFH;
}

FourOfAKind::~FourOfAKind() {
}