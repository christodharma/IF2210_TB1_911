#include "../../src/MapCard.cpp"
#include "../../src/Card.cpp"
#include "../../src/InventoryHolder.cpp"
#include "../../src/Valueable.cpp"
#include <iostream>
using namespace std;

int main(){
    CardInventory invP1;
    Card a('h', 12);
    Card b('B', 1);
    invP1 += a;
    invP1 += b;
    CardInventory invTable;
    Card o(5,'K');
    Card p(9,'m');
    Card q(5,'K');
    Card r(9,'m');
    Card s(5,'K');
    invTable += o;
    invTable += p;
    invTable += q;
    invTable += r;
    invTable += s;
    invP1.showInventory();
    invTable.showInventory();
    MapCard map(invP1, invTable);
    map.showMapCard();
    cout << map.getCardAngka("12") << endl;
    cout << map.getCardColor('H') << endl;
    map.getHold().showInventory();

    return 0;
}