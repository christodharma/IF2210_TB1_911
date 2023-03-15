#include "Flush.hpp"

Flush::Flush(map<string, InventoryHolder> mapcard) : Value(0) {
    double flash = 0;
    string m(1, 'M');
    string k(1, 'K');
    string b(1, 'B');
    string h(1, 'H');
    // cout << this->mapcard[m].getInventory().size() << endl;
    // cout << this->mapcard[k].getInventory().size() << endl;
    // cout << this->mapcard[b].getInventory().size() << endl;
    // cout << this->mapcard[h].getInventory().size() << endl;
    if (mapcard[m].getInventory().size() >= 5) {
        for (int i = 0; i<mapcard[m].getInventory().size(); i++) {
            flash += mapcard[m].getInventory()[i].getValue();
        }
    } else if (mapcard[k].getInventory().size() >= 5) {
        for (int i = 0; i<mapcard[k].getInventory().size(); i++) {
            flash += mapcard[k].getInventory()[i].getValue();
        }
    } else if (mapcard[b].getInventory().size() >= 5) {
        for (int i = 0; i<mapcard[b].getInventory().size(); i++) {
            flash += mapcard[b].getInventory()[i].getValue();
        }
    } else if (mapcard[h].getInventory().size() >= 5) {
        for (int i = 0; i<mapcard[h].getInventory().size(); i++) {
            flash += mapcard[h].getInventory()[i].getValue();
        }
    }
    this->value = flash + 6.95;
}

Flush::~Flush() {}