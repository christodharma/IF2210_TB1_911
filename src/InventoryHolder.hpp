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
class InventoryHolder{
public:
    InventoryHolder(){};
    virtual ~InventoryHolder() {};
    virtual bool isEmpty(){};
    virtual void showInventory(){};
    virtual vector<Card>& getInventory(){};
    virtual vector<Card>& operator+=(Card&){};
    virtual vector<Card>& operator-=(Card&){};
};

class Inventory : public InventoryHolder{
protected:
    /*pake card pointer masi belum tentu ide bagus
    soalnya semua kartu jadi harus unik(punya address yang beda2), jadi ga memungkinkan buat fleksibilitas? 
    tapi dengan cuman oper2 pointer jadinya game lebih efisien (ngoper alamat doang) + kalo mau jadi fleksibel, berarti cuman arahin supaya deklarasi di main yang diubah aturannya*/
    vector<Card> inventory;
public:
    /*ctor, dtor*/
    Inventory();
    ~Inventory();

    /*operator overloadings*/
    //menambahkan kartu ke dalam inventory
    vector<Card>& operator+=(Card&);
    //menghilangkan kartu yang bernilai sesuai dengan input
    vector<Card>& operator-=(Card&); //bisa rancu karena input bisa berupa kartu yang memang berada di inventory, atau bisa berupa kartu yang bernilai sama persis (bingung apa yang diminta)
    /*Belum bisa soalnya operator+= -= eksklusif buat Inventory class, tapi friend nerima vector<T*>& aja
    Maksudnya dibikin friend supaya bisa diimplement ke Player class tanpa harus redefine (not DRY)*/
    // friend vector<Card>& operator+ (vector<Card>&,Card&);
    // friend vector<Card>& operator- (vector<Card>&,Card&);
    /*inheritance methods*/
    void showInventory();
    bool isEmpty();
    vector<Card>& getInventory();
};

#endif