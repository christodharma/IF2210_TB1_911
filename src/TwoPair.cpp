#include "TwoPair.hpp"

TwoPair::TwoPair(InventoryHolder hold, map<string, InventoryHolder> mapcard) : Value(0) {
    this->hold = hold;
    this->mapcard = mapcard;
    for (int i = 1; i <= 13; i++) {
        if (this->mapcard[to_string(i)].getInventory().size() == 2) {
            double kartu1 = this->mapcard[to_string(i)].getInventory()[0].getValue();
            double kartu2 = this->mapcard[to_string(i)].getInventory()[1].getValue();
            if (kartu1 > kartu2) {
                this->value = kartu1 + 2.78;
            }
            else {
                this->value = kartu2 + 2.78;
            }
        }
    }
}
// two pair ngeliat pair yg paling gede 
// nah pair yang paling gede rumusnya 
// sama kayak pair biasa berarti 
// pair = (int * 0.1 + value warna1) + 
// (int * 0.1 + value warna2)  + 
// 0.1 * (value warna2) + 
// 4.149 
// WARNA2 HARUS LEBIH TINGGI DARI 
// WARNA1 (max = 2.759 + 4.149)
TwoPair::~TwoPair() {}