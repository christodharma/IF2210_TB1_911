#include "HighCard.hpp"

#include <iostream>
#include <string>

using namespace std;

HighCard::HighCard(map<string, InventoryHolder> mapcard) : Value(0) {
    for (int i = 13; i > 0; i--) {
        if (mapcard[to_string(i)].getInventory().size() > 0) {
            this->value = mapcard[to_string(i)].getInventory()[0].getValue();
            break;
        }
    }
}

HighCard::~HighCard() {
}

double HighCard::getValue() {
    return this->value;
}