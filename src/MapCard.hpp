#ifndef __MAPCARD_HPP__
#define __MAPCARD_HPP__

#include "Valueable.hpp"
#include "Card.hpp"
#include "InventoryHolder.hpp"

#include <iostream>
#include <map>
#include <string>
using namespace std;

class MapCard {
    private:
        CardInventory hold; // kombinasi kartu
        map<string, int> cardangka; // string = angka ("2", ..., "13"), int = jumlah kartu dengan angka tersebut
        map<char, int> cardcolor;
    public:
        MapCard(); // ctor
        MapCard(CardInventory inv, CardInventory table); // ctor dengan parameter (inventory player dan table
        ~MapCard(); // dtor
        void setMap(CardInventory inv, CardInventory table); // mengisi map dengan kartu yang ada di inventory player dan table
        CardInventory getHold(); // mengembalikan inventory di tangan dan table
        map<string, int> getCardAngka(); // mengembalikan map cardangka
        map<char, int> getCardColor(); // mengembalikan map cardcolor
        void addCard(Card); // menambahkan kartu ke map
        void removeCard(Card); // menghapus kartu dari map
        int getCardAngka(string); // mengembalikan jumlah kartu dengan angka yang sama dengan kartu yang diberikan
        int getCardColor(char); // mengembalikan jumlah kartu dengan warna yang sama dengan kartu yang diberikan
        void showMapCard(); // print isi map
};

#endif