#include "Flush.hpp"

Flush::Flush(InventoryHolder hold, map<string, InventoryHolder> mapcard) : Value(0) {
    this->hold = hold;
    this->mapcard = mapcard;
    double flash = 0;
    string m(1, 'M');
    string k(1, 'K');
    string b(1, 'B');
    string h(1, 'H');
    // cout << this->mapcard[m].getInventory().size() << endl;
    // cout << this->mapcard[k].getInventory().size() << endl;
    // cout << this->mapcard[b].getInventory().size() << endl;
    // cout << this->mapcard[h].getInventory().size() << endl;
    if (this->mapcard[m].getInventory().size() >= 5) {
        for (int i = 0; i<this->mapcard[m].getInventory().size(); i++) {
            flash += this->mapcard[m].getInventory()[i].getValue();
        }
    } else if (this->mapcard[k].getInventory().size() >= 5) {
        for (int i = 0; i<this->mapcard[k].getInventory().size(); i++) {
            flash += this->mapcard[k].getInventory()[i].getValue();
        }
    } else if (this->mapcard[b].getInventory().size() >= 5) {
        for (int i = 0; i<this->mapcard[b].getInventory().size(); i++) {
            flash += this->mapcard[b].getInventory()[i].getValue();
        }
    } else if (this->mapcard[h].getInventory().size() >= 5) {
        for (int i = 0; i<this->mapcard[h].getInventory().size(); i++) {
            flash += this->mapcard[h].getInventory()[i].getValue();
        }
    }
    this->value = flash + 6.95;
}

Flush::~Flush() {}