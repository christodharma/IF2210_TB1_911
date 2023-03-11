#ifndef __MAPVALUECARD_HPP__
#define __MAPVALUECARD_HPP__

#include <iostream>
#include <map>
#include <string>
#include "InventoryHolder.hpp"
using namespace std;

class MapValueCard {
    private:
        map<string, int> mapcard; // string = angka ("2", ..., "13"), int = jumlah kartu dengan angka tersebut
    public:
        MapValueCard(); // ctor
        ~MapValueCard(); // dtor
        void setMap(CardInventory inv, CardInventory table); // mengisi map dengan kartu yang ada di inventory player dan table
        void addCard(Card); // menambahkan kartu ke map
        void removeCard(Card); // menghapus kartu dari map
        int getCardValue(string); // mengembalikan jumlah kartu dengan angka yang sama dengan kartu yang diberikan
        void showMapValueCard(); // print isi map
};

#endif