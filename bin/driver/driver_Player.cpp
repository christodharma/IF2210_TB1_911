#include "../../src/InventoryHolder.hpp"
#include "../../src/Player.hpp"
#include "../../src/Card.hpp"
#include "../../src/Valueable.hpp"
#include "../../src/Deck.hpp"
#include "../../src/Ability.hpp"
#include <iostream>
using namespace std;


//compile
/*
g++ -o driver_Player driver_Player.cpp ../../src/InventoryHolder.cpp ../../src/Player.cpp ../../src/Card.cpp ../../src/Valueable.cpp ../../src/Deck.cpp ../../src/Ability.cpp; if ($?) {./driver_Player}
*/
int main(){
    Player p1("Alice");
    Player p2("Bobby");
    Deck deck;
    deck.ShuffleDeck();
    cout << "Player name: "<<p1.getPlayerName() << endl;
    cout << "Player point: "<<p1.getPlayerPoint() << endl;
    cout << "Player name: "<<p2.getPlayerName() << endl;
    cout << "Player point: "<<p2.getPlayerPoint() << endl;
    p1.showInventory();
    p2.showInventory();
    p1 += deck.Draw(); //harusnya BUKAN 13 merah
    p2 += deck.Draw(); //harusnya BUKAN 12 merah
    p1.showInventory();
    p2.showInventory();
    return 0;
}