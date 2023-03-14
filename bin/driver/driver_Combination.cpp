#include "../../src/Combination.cpp"
#include "../../src/Card.cpp"
#include "../../src/InventoryHolder.cpp"
#include "../../src/Valueable.cpp"
#include "../../src/FourOfAKind.cpp"
#include "../../src/Straight.cpp"
#include "../../src/Flush.cpp"
#include <iostream>
using namespace std;

int main(){
    InventoryHolder invP1;
    Card a('h', 12);
    Card b('m', 12);
    invP1 += a;
    invP1 += b;

    InventoryHolder invP2;
    Card h('h', 5);
    Card i('h', 6);
    invP2 += h;
    invP2 += i;

    InventoryHolder invP3;
    Card j('b', 5);
    Card k('b', 7);
    invP3 += j;
    invP3 += k;

    InventoryHolder table;
    Card c('k', 12);
    Card d('B', 3);
    // Card e('b', 12);
    Card e('m', 7);
    Card f('B', 4);
    Card g('m', 2);
    table += c;
    table += d;
    table += e;
    table += f;
    table += g;

    Combination com(invP1, table);
    com.showCombination();
    cout << com.getByParameter("B").getInventory()[0].getAngka() << endl;
    cout << com.getByParameter("B").getInventory().size() << endl;
    // cout << com.getValue() << endl;

    Combination str(invP2, table);
    str.showCombination();
    cout << str.getValue() << endl;

    Combination fls(invP3, table);
    fls.showCombination();
    cout << fls.getValue() << endl;

    return 0;
}