#ifndef __INVENTORYHOLDER_HPP__
#define __INVENTORYHOLDER_HPP__

#include "Card.hpp"
#include <vector>
#include <string>
#include <utility>
#include <iostream>
using namespace std;


// Kelas abstract yang di-inherit ke GameState dan Player
// Berkaitan dalam hal kepemilikan kartu
template <class T>
class InventoryHolder{
protected:
    vector<T> inventory;
public:
    InventoryHolder();
    ~InventoryHolder();
    bool isEmpty();
    void showInventory() const;
    vector<T>& getInventory();
    vector<T>& operator+=(T&);
    vector<T>& operator-=(T&);
    vector<T>& operator+(T&);
    vector<T>& operator-(T&);
};

#endif