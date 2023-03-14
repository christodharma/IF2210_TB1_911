#include "../../src/Combination.cpp"
#include "../../src/Card.cpp"
#include "../../src/InventoryHolder.cpp"
#include "../../src/Valueable.cpp"
#include "../../src/FourOfAKind.cpp"
#include <iostream>
using namespace std;

int main(){
    CardInventory invP1;
    Card a('h', 12);
    Card b('B', 2);
    invP1 += a;
    invP1 += b;
    CardInventory table;
    Card c('h', 12);
    Card d('B', 3);
    Card e('h', 12);
    Card f('B', 4);
    Card g('h', 12);
    table += c;
    table += d;
    table += e;
    table += f;
    table += g;
    Combination com(invP1, table);
    com.showCombination();
    cout << com.getByParameter("B").getInventory()[0].getAngka() << endl;
    cout << com.getByParameter("B").getInventory().size() << endl;
    cout << com.getValue() << endl;

    return 0;
}