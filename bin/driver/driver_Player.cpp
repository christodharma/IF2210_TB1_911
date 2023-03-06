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
    cout << "Player name: "<<p1.getPlayerName() << endl;
    cout << "Player point: "<<p1.getPlayerPoint() << endl;
    p1.showInventory();
    Card h13('h', 13);
    Card b13('b', 13);
    p1 += b13;
    p1 += h13;
    p1.showInventory();
    // p1 - h13; //error di erase()
    // p1.showInventory();
    return 0;
}