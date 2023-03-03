#ifndef __INVENTORYHOLDER_HPP__
#define __INVENTORYHOLDER_HPP__

#include "Card.hpp"
#include <vector>
#include <string>
using namespace std;


//Kelas abstract yang di-inherit ke GameState dan Player
//Berkaitan dalam hal kepemilikan kartu
class InventoryHolder : Card{
protected:
    vector<Card> inventory;
// public:
    // virtual Card* getInventory();
};

class GameState: InventoryHolder, Card {
private:
    //vector <Card> inventory dari inventoryholder
    int round;
    static long int prize;
    static bool isOngoing;
};

#endif