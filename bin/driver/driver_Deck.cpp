#include "../../src/Deck.hpp"
#include <iostream>
using namespace std;

/*
g++ -o driver_Deck driver_Deck.cpp ../../src/Deck.cpp ../../src/InventoryHolder.cpp ../../src/Card.cpp ../../src/Valueable.cpp; if ($?) {./driver_Deck}
*/

int main(){
    Deck deck;
    Inventory inv;
    deck.showInventory();
    deck.ShuffleDeck();
    deck.DrawTo(inv.getInventory());
    inv.showInventory();
    return 0;
}