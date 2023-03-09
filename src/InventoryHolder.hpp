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
    virtual vector<pair<char,int>>& getInventory()=0;
    virtual vector<pair<char,int>>& operator+=(Card&)=0;
    virtual vector<pair<char,int>>& operator-=(Card&)=0;
    virtual vector<pair<char,int>>& operator+(Card&)=0;
    virtual vector<pair<char,int>>& operator-(Card&)=0;
};

class CardInventory : public InventoryHolder{
protected:
    /*pake card pointer masi belum tentu ide bagus
    soalnya semua kartu jadi harus unik(punya address yang beda2), jadi ga memungkinkan buat fleksibilitas? 
    tapi dengan cuman oper2 pointer jadinya game lebih efisien (ngoper alamat doang) + kalo mau jadi fleksibel, berarti cuman arahin supaya deklarasi di main yang diubah aturannya*/
    vector<pair<char,int>> inventory;
public:
    /*ctor, dtor*/
    CardInventory();
    ~CardInventory();

    /*operator overloadings*/
    //menambahkan kartu ke dalam inventory
    vector<pair<char,int>>& operator+=(Card&);
    //menghilangkan kartu yang bernilai sesuai dengan input
    vector<pair<char,int>>& operator-=(Card&); //bisa rancu karena input bisa berupa kartu yang memang berada di inventory, atau bisa berupa kartu yang bernilai sama persis (bingung apa yang diminta)
    vector<pair<char,int>>& operator+ (Card&);
    vector<pair<char,int>>& operator- (Card&);
    /*inheritance methods*/
    void showInventory();
    bool isEmpty();
    vector<pair<char,int>>& getInventory();
};

#endif