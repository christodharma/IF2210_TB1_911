#include "../../src/Combination.cpp"
#include "../../src/Card.cpp"
#include "../../src/InventoryHolder.cpp"
#include "../../src/Valueable.cpp"
#include "../../src/FourOfAKind.cpp"
#include "../../src/TwoPair.cpp"
#include "../../src/ThreeOfAKind.cpp"
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

    InventoryHolder table;
    Card e('H', 3);
    Card f('B', 8);
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
    return 0;
}