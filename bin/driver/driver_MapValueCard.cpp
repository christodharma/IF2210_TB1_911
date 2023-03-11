
#include "../../src/MapValueCard.hpp"
#include "../../src/Card.hpp"
#include "../../src/InventoryHolder.hpp"
#include <iostream>
using namespace std;

int main(){
    CardInventory invP1;
    Card a('h', 12);
    Card b('B', 1);
    invP1 += a;
    invP1 += b;
    CardInventory invP2;
    Card c(5,'K');
    Card d(9,'m');
    invP2 += c;
    invP2 += d;
    CardInventory invP3;
    Card e(5,'K');
    Card f(9,'m');
    invP3 += e;
    invP3 += f;
    CardInventory invP4;
    Card g(5,'K');
    Card h(9,'m');
    invP4 += g;
    invP4 += h;
    CardInventory invP5;
    Card i(5,'K');
    Card j(9,'m');
    invP5 += i;
    invP5 += j;
    CardInventory invP6;
    Card k(5,'K');
    Card l(9,'m');
    invP6 += k;
    invP6 += l;
    CardInventory invP7;
    Card m(5,'K');
    Card n(9,'m');
    invP7 += m;
    invP7 += n;
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
    MapValueCard map;
    map.setMap(invP1, invTable);
    map.showMapValueCard();
    cout << map.getCardValue("12");

    return 0;
}