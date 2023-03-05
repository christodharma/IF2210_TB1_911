#ifndef __INVENTORYHOLDER_HPP__
#define __INVENTORYHOLDER_HPP__

#include "Card.hpp"
#include <vector>
#include <string>
using namespace std;


// Kelas abstract yang di-inherit ke GameState dan Player
// Berkaitan dalam hal kepemilikan kartu
// (maybe ini yang bakal jadi template class
// soalnya collection of object)
template <class T>
class InventoryHolder{
public:
    InventoryHolder(){};
    // virtual ~InventoryHolder();
    virtual bool isEmpty(){};
    // virtual vector<T*> getInventory();
};

class CardInventory : public InventoryHolder<Card>{
protected:
    vector<Card*> inv;
public:
    CardInventory();
    ~CardInventory();
    bool isEmpty();
    // vector<Card*> getInventory();
};

class GameState: public InventoryHolder<Card>{
private:
    //vector <Card> inventory dari inventoryholder
    int round;
    static long int prize;
    static bool isOngoing;
public:
    int getRound();
    long int getPrize();
    bool isGameOngoing();
    bool isEmpty();
};

#endif