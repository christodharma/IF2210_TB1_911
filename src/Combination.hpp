#ifndef __COMBINATION_HPP__
#define __COMBINATION_HPP__

#include <iostream>
#include <map>
#include <string>
#include "Valueable.hpp"
#include "Card.hpp"
#include "InventoryHolder.hpp"
#include "FourOfAKind.hpp"
#include "FullHouse.hpp"
// ... include semua jenis tipe kombinasi
using namespace std;

class Combination {
    private:
        CardInventory hold; // kombinasi kartu
        map<string, int> mapcard; // string = angka ("2", ..., "13"), int = jumlah kartu dengan angka tersebut
        map<char, int> cardcolor;
        Value *value; // pointer value untuk menghitung nilai kombinasi
    public:
        Combination(); // ctor
        Combination(CardInventory inv, CardInventory table); // ctor dengan parameter (inventory player dan table
        ~Combination(); // dtor
        void setMap(CardInventory inv, CardInventory table); // mengisi map dengan kartu yang ada di inventory player dan table
        void addCard(Card); // menambahkan kartu ke map
        void removeCard(Card); // menghapus kartu dari map
        int getCardValue(string); // mengembalikan jumlah kartu dengan angka yang sama dengan kartu yang diberikan
        int getCardColor(char); // mengembalikan jumlah kartu dengan warna yang sama dengan kartu yang diberikan
        void showCombination(); // print isi map
        CardInventory getHold(); // mengembalikan inventory di tangan dan table
        double getValue(); // mengembalikan value
        void setValue(Value *value); // mengeset pointer value
        bool isThere2Angka(); // cek apakah ada 2 kartu yang sama
        bool isThere3Angka(); // cek apakah ada 3 kartu yang sama
        bool isThere4Angka(); // cek apakah ada 4 kartu yang sama
        bool isThere5Warna(); // cek apakah ada 5 kartu dengan warna yang sama
        bool isThereStraight(); // cek apakah ada 5 kartu dengan angka berurutan
};

#endif