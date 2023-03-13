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
        InventoryHolder hold; // kombinasi kartu
        map<string, InventoryHolder> mapcard;
        Value *value; // pointer value untuk menghitung nilai kombinasi
    public:
        Combination(); // ctor
        Combination(InventoryHolder inv, InventoryHolder table); // ctor dengan parameter (inventory player dan table
        ~Combination(); // dtor
        void setMap(InventoryHolder inv, InventoryHolder table); // mengisi map dengan kartu yang ada di inventory player dan table
        void addCard(Card); // menambahkan kartu ke map
        void removeCard(Card); // menghapus kartu dari map
        InventoryHolder getByParameter(string input); // mengembalikan inventory kartu dengan angka yang sama dengan kartu yang diberikan
        void showCombination(); // print isi map
        InventoryHolder getHold(); // mengembalikan inventory di tangan dan table
        double getValue(); // mengembalikan value
        void setValue(Value *value); // mengeset pointer value
        int isThere2Angka(); // cek apakah ada 2 kartu yang sama
        int isThere3Angka(); // cek apakah ada 3 kartu yang sama
        int isThere4Angka(); // cek apakah ada 4 kartu yang sama
        bool isThereFlush(); // cek apakah ada 5 kartu dengan warna yang sama
        bool isThereStraight(); // cek apakah ada 5 kartu dengan angka berurutan
};

#endif