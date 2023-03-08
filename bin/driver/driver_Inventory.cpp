#include "../../src/Card.hpp"
#include "../../src/InventoryHolder.hpp"
#include "../../src/Valueable.hpp"
#include <iostream>
using namespace std;

//g++ -o driver_Inventory driver_Inventory.cpp ../../src/Card.cpp ../../src/InventoryHolder.cpp ../../src/Valueable.cpp

int main(){
    CardInventory inv;
    Card a('h', 12);
    Card b('B', 1);
    Card c(5,'K');
    Card d(9,'m');
    inv += a;
    inv += b;
    inv += c;
    inv += d;
    cout << a.getValue() << endl;
    cout << b.getValue() << endl;
    cout << c.getValue() << endl;
    cout << d.getValue() << endl;
    inv.showInventory();
    inv -= c;
    inv.showInventory();
    return 0;
}