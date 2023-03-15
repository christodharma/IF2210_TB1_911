#include "Straight.hpp"

Straight::Straight(map<string, InventoryHolder> mapcard) : Value(0) {
    double straight = 0;
    int count = 0;
    for (int i=1; i<=13; i++) {
        if (mapcard[to_string(i)].getInventory().size() >= 1) {
            count++;
        } else {
            count = 0;
        }
        if (count >= 5) {
            straight = mapcard[to_string(i)].getInventory()[0].getValue();
        }
    }
    this->value = straight + 5.56;
}

Straight::~Straight() {}

// InventoryHolder Straight::getCardStraight(map<string, InventoryHolder> mapcard) {
//     map<string, InventoryHolder> straightcard;
//     straightcard["0"] = InventoryHolder();
//     for (int i=1; i<=13; i++) {
//         if (mapcard[to_string(i)].getInventory().size() >= 1) {
//             straightcard["0"].getInventory() += mapcard[to_string(i)].getInventory();
//         } else {
//             straightcard["0"] = InventoryHolder();
//         }
//     }
//     printVectorCard(straightcard["0"].getInventory());
// }