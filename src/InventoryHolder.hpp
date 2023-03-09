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
public:
    InventoryHolder(){};
    virtual ~InventoryHolder() {};
    virtual bool isEmpty()=0;
    virtual void showInventory()=0;
    virtual vector<Card>& getInventory()=0;
    virtual vector<Card>& operator+=(Card&)=0;
    virtual vector<Card>& operator-=(Card&)=0;
    virtual vector<Card>& operator+(Card&)=0;
    virtual vector<Card>& operator-(Card&)=0;
};

//maybe ini yang bakal jadi template class, rename Container
class CardInventory : public InventoryHolder{
protected:
    vector<Card> inventory;
public:
    /*ctor, dtor*/
    CardInventory();
    ~CardInventory();

    /*operator overloadings*/
    //menambahkan kartu ke dalam inventory
    vector<Card>& operator+=(Card&);
    //menghilangkan kartu yang bernilai sesuai dengan input
    vector<Card>& operator-=(Card&); //bisa rancu karena input bisa berupa kartu yang memang berada di inventory, atau bisa berupa kartu yang bernilai sama persis (bingung apa yang diminta)
    vector<Card>& operator+ (Card&);
    vector<Card>& operator- (Card&);
    /*inheritance methods*/
    void showInventory();
    bool isEmpty();
    vector<Card>& getInventory();
};

#endif