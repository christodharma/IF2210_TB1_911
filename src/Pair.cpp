#include "Pair.hpp"

#include <iostream>
#include <string>

using namespace std;

Pair :: Pair(map<string, InventoryHolder> mapcard) : Value(0) {
    for (int i = 13; i > 0; i--) {
        if (mapcard[to_string(i)].getInventory().size() == 2) {
            double value1 = mapcard[to_string(i)].getInventory()[0].getValue();
            double value2 = mapcard[to_string(i)].getInventory()[1].getValue();
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