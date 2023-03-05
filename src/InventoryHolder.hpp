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
    virtual ~InventoryHolder() {};
    virtual bool isEmpty(){};
    virtual void showInventory(){};
    virtual vector<T*>& getInventory(){};
};

class CardInventory : public InventoryHolder<Card>{
protected:
    vector<Card*> inv;
public:
    /*ctor, dtor*/
    CardInventory();
    ~CardInventory();

    /*operator overloadings*/
    //menambahkan kartu ke dalam inventory
    vector<Card*>& operator+(Card&);
    //menghilangkan kartu yang bernilai sesuai dengan input
    vector<Card*>& operator-(Card&); //bisa rancu karena input bisa berupa kartu yang memang berada di inventory, atau bisa berupa kartu yang bernilai sama persis (bingung apa yang diminta)
    // friend vector<Card*>& Player::operator+(Card&);
    // friend vector<Card*>& Player::operator-(Card&);
    /*inheritance methods*/
    void showInventory();
    bool isEmpty();
    vector<Card*>& getInventory();
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

    //inheritance methods
    void showInventory();
    bool isEmpty();
};

#endif