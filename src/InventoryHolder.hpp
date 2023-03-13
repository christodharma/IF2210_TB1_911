#ifndef __INVENTORYHOLDER_HPP__
#define __INVENTORYHOLDER_HPP__

#include "Card.hpp"
#include <vector>
#include <string>
#include <utility>
using namespace std;


// Kelas abstract yang di-inherit ke GameState dan Player
// Berkaitan dalam hal kepemilikan kartu
// (maybe ini yang bakal jadi template class
// soalnya collection of object)
class InventoryHolder{
protected:
    vector<Card> inventory;
public:
    InventoryHolder();
    ~InventoryHolder();
    bool isEmpty();
    void showInventory() const;
    vector<Card>& getInventory();
    vector<Card>& operator+=(Card&);
    vector<Card>& operator-=(Card&);
    vector<Card>& operator+(Card&);
    vector<Card>& operator-(Card&);
};

#endif