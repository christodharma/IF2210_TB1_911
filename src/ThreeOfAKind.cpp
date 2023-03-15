#include "ThreeOfAKind.hpp"

ThreeOfAKind::ThreeOfAKind(map<string, InventoryHolder> mapcard) : Value(0) {
    int pair = 0;
    for (int i = 1; i <= 13; i++) {
        for (int j = 0; j < 3; j++) {
            if (mapcard[to_string(i)].getInventory().size() == 3) {
                this->value = mapcard[to_string(i)].getInventory()[j].getValue() + 4.17;
            }
        }
    }
}

ThreeOfAKind::~ThreeOfAKind() {}