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
#include "../../src/HighCard.cpp"
#include "../../src/Pair.cpp"
#include "../../src/StraightFlush.cpp"
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

    InventoryHolder invP5;
    Card n('b', 5);
    Card o('m', 8);
    invP5 += n;
    invP5 += o;

    InventoryHolder invP6;
    Card z('b', 5);
    Card zz('m', 1);
    invP6 += z;
    invP6 += zz;

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

    InventoryHolder table1;
    Card p('M', 6);
    Card q('M', 9);
    Card r('M', 7);
    Card s('K', 10);
    Card t('M', 5);
    table1 += p;
    table1 += q;
    table1 += r;
    table1 += s;
    table1 += t;

    InventoryHolder table2;
    Card u('M', 6);
    Card v('B', 7);
    Card w('M', 7);
    Card x('K', 10);
    Card y('M', 5);
    table2 += u;
    table2 += v;
    table2 += w;    
    table2 += x;
    table2 += y;

    InventoryHolder table3;
    Card a1('M', 6);
    Card b1('B', 8);
    Card c1('M', 8);
    Card d1('K', 8);
    Card e1('M', 5);
    table3 += a1;
    table3 += b1;
    table3 += c1;
    table3 += d1;
    table3 += e1;

    //StraightFlush
    Combination strFl(invP5, table1);
    strFl.showCombination();

    //FourOfAKind
    Combination fourOAK(invP2, table2);
    fourOAK.showCombination();

    //FullHouse
    Combination fullH(invP2, table3);
    fullH.showCombination();

    //flush
    Combination fls(invP4, table);
    fls.showCombination();
    // cout << fls.getValue() << endl;

    //straight
    Combination str(invP3, table);
    str.showCombination();
    // cout << str.getValue() << endl;

    //threeOfAKind
    Combination threeOAK(invP2, table);
    threeOAK.showCombination();

    //twoPair
    Combination twoP(invP1, table);
    twoP.showCombination();

    //Pair
    Combination pr(invP5, table);
    pr.showCombination();

    //HighCard
    Combination hc(invP6, table);
    hc.showCombination();

    return 0;
}