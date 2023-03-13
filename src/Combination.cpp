#include "Combination.hpp"
#include <iostream>
#include <string>

using namespace std;

Combination::Combination(){
    for (int i=0; i<13; i++) {
        this->mapcard[to_string(i)] = 0;
    }
    for (int i=0; i<4; i++) {
        this->cardcolor[i] = 0;
    }    
}

Combination::~Combination(){
}

void Combination::setMap(CardInventory hand, CardInventory table){
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
    this->mapcard[to_string(input.getAngka())]++;
    this->cardcolor[input.getWarna()]++;
    this->hold += input;
}

void Combination::removeCard(Card input){
    this->mapcard[to_string(input.getAngka())]--;
    this->cardcolor[input.getWarna()]--;
    this->hold -= input;
}

int Combination::getCardValue(string input){
    return this->mapcard[input];
}

int Combination::getCardColor(char input){
    return this->cardcolor[input];
}

void Combination::showCombination(){
    for (int i=0; i<13; i++){
        cout << i << " : " << this->mapcard[to_string(i)] << endl;
    }
    cout << "Merah : " << this->cardcolor['M'] << endl;
    cout << "Kuning : " << this->cardcolor['K'] << endl;
    cout << "Hijau : " << this->cardcolor['H'] << endl;
    cout << "Biru : " << this->cardcolor['B'] << endl;
}

CardInventory getHold() {
    return this->hold;
} // mengembalikan inventory di tangan dan table

double getValue() {
    return this->value->getValue();
} // mengembalikan value

void setValue(Value *value) {
    this->value = value;
} // mengeset pointer value

bool isThere2Angka() {
    for (int i=0; i<13; i++) {
        if (this->mapcard[to_string(i)] == 2) {
            return true;
        }
    }
    return false;
} // cek apakah ada 2 kartu yang sama

bool isThere3Angka() {
    for (int i=0; i<13; i++) {
        if (this->mapcard[to_string(i)] == 3) {
            return true;
        }
    }
    return false;
} // cek apakah ada 3 kartu yang sama

bool isThere4Angka() {
    for (int i=0; i<13; i++) {
        if (this->mapcard[to_string(i)] == 4) {
            return true;
        }
    }
    return false;
} // cek apakah ada 4 kartu yang sama

bool isThere5Warna() {
    for (int i=0; i<4; i++) {
        if (this->cardcolor[i] == 5) {
            return true;
        }
    }
    return false;
} // cek apakah ada 5 kartu dengan warna yang sama

bool isThereStraight() {
    int count = 0;
    for (int i=0; i<13; i++) {
        if (this->mapcard[to_string(i)] == 1) {
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