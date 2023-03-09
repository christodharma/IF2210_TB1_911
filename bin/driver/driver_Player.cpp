#include "../../src/InventoryHolder.hpp"
#include "../../src/Player.hpp"
#include "../../src/Card.hpp"
#include "../../src/Valueable.hpp"
#include <iostream>
using namespace std;


//compile
//g++ -o driver_Player driver_Player.cpp ../../src/InventoryHolder.cpp ../../src/Player.cpp ../../src/Card.cpp ../../src/Valueable.cpp
int main(){
    Player p1("Alice");
    Player p2("Bobby");
    Card h13('h', 13);
    Card b13('b', 13);
    Card k1('k', 1);
    Card m2('m', 2);
    Card b5('b', 5);
    cout << "Player name: "<<p1.getPlayerName() << endl;
    cout << "Player point: "<<p1.getPlayerPoint() << endl;
    cout << "Player name: "<<p2.getPlayerName() << endl;
    cout << "Player point: "<<p2.getPlayerPoint() << endl;
    p1.showInventory();
    p2.showInventory();
    p1 += b13;
    p1 += h13;
    p2 += h13;
    p1 + k1;
    p1.showInventory();
    p2.showInventory();
    p1 -= h13;
    p2 - b13;
    p1.showInventory();
    p2.showInventory();
    return 0;
}