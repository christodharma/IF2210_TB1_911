#include "Combination.hpp"
#include <iostream>
#include <string>

using namespace std;

Combination::Combination(){
    for (int i = 1; i <= 13; i++) {
        this->mapcard[to_string(i)] = InventoryHolder();
    }
    this->mapcard["M"] = InventoryHolder();
    this->mapcard["K"] = InventoryHolder();
    this->mapcard["H"] = InventoryHolder();
    this->mapcard["B"] = InventoryHolder();
}

Combination::Combination(InventoryHolder hand, InventoryHolder table) {
    for (int i = 1; i <= 13; i++) {
        this->mapcard[to_string(i)] = InventoryHolder();
    }
    this->mapcard["M"] = InventoryHolder();
    this->mapcard["K"] = InventoryHolder();
    this->mapcard["H"] = InventoryHolder();
    this->mapcard["B"] = InventoryHolder();

    for (int i = 0; i < hand.getInventory().size(); i++) {
        this->addCard(hand.getInventory()[i]);
        this->hold += hand.getInventory()[i];
    }
    for (int i = 0; i < table.getInventory().size(); i++) {
        this->addCard(table.getInventory()[i]);
        this->hold += table.getInventory()[i];
    }

    if (this->isThere4Angka()) {
        int i = 1;
        while (this->mapcard[to_string(i)].getInventory().size() < 4) {
            i++;
        }
        this->value = new FourOfAKind(i); 
    }
    else if (this->isThere3Angka() == 2) {
        int i = 13;
        while (this->mapcard[to_string(i)].getInventory().size() < 3) {
            i--;
        }
        this->value = new FullHouse(i);
    }
    else if (this->isThere3Angka() && this->isThere2Angka()) {
        int i = 1;
        while (this->mapcard[to_string(i)].getInventory().size() < 3) {
            i++;
        }
        this->value = new FullHouse(i);
    }
}

Combination::~Combination(){
}

void Combination::setMap(InventoryHolder hand, InventoryHolder table){
    for (int i=0; i<hand.getInventory().size(); i++){
        this->addCard(hand.getInventory()[i]);
        this->hold += hand.getInventory()[i];
    }
    for (int i=0; i<table.getInventory().size(); i++){
        this->addCard(table.getInventory()[i]);
        this->hold += table.getInventory()[i];
    }
}

void Combination::addCard(Card input){
    this->mapcard[to_string(input.getAngka())] += input;
    string color(1, input.getWarna());
    this->mapcard[color] += input;
    this->hold += input;
}

void Combination::removeCard(Card input){
    this->mapcard[to_string(input.getAngka())] -= input;
    string color(1, input.getWarna());
    this->mapcard[color] -= input;
    this->hold -= input;
}

InventoryHolder Combination::getByParameter(string parameter) {
    return this->mapcard[parameter];
} // mengembalikan inventory berdasarkan parameter

void printVectorCard(vector<Card> input) {
    cout << "< ";
    for (int i = 0; i < input.size(); i++) {
        cout << "(" << input[i].getAngka() << ", " << input[i].getWarna() << ") ";
    }
    cout << ">" << endl;
}

void Combination::showCombination(){
    for (int i = 1; i <= 13; i++) {
        cout << i << " : ";
        printVectorCard(this->mapcard[to_string(i)].getInventory());
    }
    cout << "Merah : ";
    printVectorCard(this->mapcard["M"].getInventory());
    cout << "Kuning : ";
    printVectorCard(this->mapcard["K"].getInventory());
    cout << "Hijau : ";
    printVectorCard(this->mapcard["H"].getInventory());
    cout << "Biru : ";
    printVectorCard(this->mapcard["B"].getInventory());
}

InventoryHolder Combination::getHold() {
    return this->hold;
} // mengembalikan inventory di tangan dan table

double Combination::getValue() {
    return this->value->getValue();
} // mengembalikan value

void Combination::setValue(Value *value) {
    this->value = value;
} // mengeset pointer value

int Combination::isThere2Angka() {
    int i = 0;
    for (int i = 1; i <= 13; i++) {
        if (this->mapcard[to_string(i)].getInventory().size() == 2) {
            return i++;
        }
    }
    return i;
} // cek apakah ada 2 kartu yang sama

int Combination::isThere3Angka() {
    int i = 0;
    for (int i = 1; i <= 13; i++) {
        if (this->mapcard[to_string(i)].getInventory().size() == 3) {
            return i++;
        }
    }
    return i;
} // cek apakah ada 3 kartu yang sama

int Combination::isThere4Angka() {
    int i = 0;
    for (int i = 1; i <= 13; i++) {
        if (this->mapcard[to_string(i)].getInventory().size() == 4) {
            return i++;
        }
    }
    return i;
} // cek apakah ada 4 kartu yang sama

bool Combination::isThereFlush() {
    string m(1, 'M');
    string k(1, 'K');
    string b(1, 'B');
    string h(1, 'H');
    if (this->mapcard[m].getInventory().size() >= 5) {
        return true;
    } else if (this->mapcard[k].getInventory().size() >= 5) {
        return true;
    } else if (this->mapcard[b].getInventory().size() >= 5) {
        return true;
    } else if (this->mapcard[h].getInventory().size() >= 5) {
        return true;
    } else {
        return false;
    }
} // cek apakah ada 5 kartu dengan warna yang sama

bool Combination::isThereStraight() {
    int count = 0;
    for (int i=0; i<13; i++) {
        if (this->mapcard[to_string(i)].getInventory().size() >= 1) {
            count++;
        } else {
            count = 0;
        }
        if (count == 5) {
            return true;
        }
    }
    return false;
} // cek apakah ada 5 kartu dengan angka berurutan

