#include "../../src/Combination.cpp"
#include "../../src/Card.cpp"
#include "../../src/InventoryHolder.cpp"
#include "../../src/Valueable.cpp"
#include "../../src/FullHouse.cpp"
#include "../../src/FourOfAKind.cpp"
#include "../../src/TwoPair.cpp"
#include "../../src/ThreeOfAKind.cpp"
#include "../../src/Straight.cpp"
#include "../../src/Flush.cpp"
#include <iostream>
using namespace std;

int main(){
    InventoryHolder invP1;
    Card a('B', 3);
    Card b('M', 8);
    invP1 += a;
    invP1 += b;

    InventoryHolder invP2;
    Card c('H', 7);
    Card d('K', 7);
    invP2 += c;
    invP2 += d;

    InventoryHolder invP3;
    Card j('h', 5);
    Card k('m', 6);
    invP3 += j;
    invP3 += k;

    InventoryHolder invP4;
    Card l('k', 5);
    Card m('k', 12);
    invP4 += l;
    invP4 += m;

    InventoryHolder table;
    Card e('H', 3);
    Card f('K', 8);
    Card g('K', 4);
    Card h('K', 10);
    Card i('M', 7);
    table += e;
    table += f;
    table += g;
    table += h;
    table += i;
    //twoPair
    Combination twoP(invP1, table);
    twoP.showCombination();
    //threeOfAKind
    Combination threeOAK(invP2, table);
    threeOAK.showCombination();

    //straight
    Combination str(invP3, table);
    str.showCombination();
    // cout << str.getValue() << endl;

    //flash
    Combination fls(invP4, table);
    fls.showCombination();
    // cout << fls.getValue() << endl;

    return 0;
}