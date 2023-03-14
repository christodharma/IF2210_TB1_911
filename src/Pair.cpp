#include "Pair.hpp"

#include <iostream>
#include <string>

using namespace std;

Pair :: Pair(map<string, InventoryHolder> mapcard) : Value(0) {
    this->mapcard = mapcard;
    for (int i = 13; i > 0; i--) {
        if (this->mapcard[to_string(i)].getInventory().size() == 2) {
            double value1 = this->mapcard[to_string(i)].getInventory()[0].getValue();
            double value2 = this->mapcard[to_string(i)].getInventory()[1].getValue();
            if (value1 > value2) {
                this->value = value1 + 1.39;
            } 
            else {
                this->value = value2 + 1.39;
            }
            break;
            
        }
    }
}

Pair :: ~Pair() {
}