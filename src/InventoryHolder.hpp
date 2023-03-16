#ifndef __INVENTORYHOLDER_HPP__
#define __INVENTORYHOLDER_HPP__

#include "Card.hpp"
#include "Exception.hpp"
#include <vector>
#include <string>
#include <utility>
#include <iostream>
using namespace std;


// Kelas abstract yang di-inherit ke GameState dan Player
// Berkaitan dalam hal kepemilikan kartu
class InventoryHolder{
public:
    InventoryHolder();
    virtual ~InventoryHolder();
    virtual bool isEmpty();
    virtual void showInventory() const;
    virtual vector<Card>& getInventory();
    virtual vector<Card>& operator+=(Card&);
    virtual vector<Card>& operator-=(Card&);
    virtual vector<Card>& operator+(Card&);
    virtual vector<Card>& operator-(Card&);
    virtual vector<Card>& operator=(const vector<Card>&);
};

#endif