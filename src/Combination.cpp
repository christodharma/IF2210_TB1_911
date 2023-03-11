#include "Combination.hpp"
#include <iostream>
using namespace std;

//Combination nerima kartu dari table, dan inventory
Combination::Combination(vector<Card> table, vector<Card> inventory){
    int size = table.size() + inventory.size();
    this->combo = new Card[size];
    for(int i=0; i<table.size(); i++){
        this->combo[i] = table[i];
    }
    for(int i=0; i<inventory.size(); i++){
        this->combo[i+table.size()] = inventory[i];
    }
    for(int i=0; i<size; i++){
        this->warna[this->combo[i].getWarna()]++;
        this->angka[this->combo[i].getAngka()]++;
    }
    //printing warna and angka map
    cout << "warna: " << endl;
    for(auto it = this->warna.begin(); it != this->warna.end(); it++){
        cout << it->first << ": " << it->second << endl;
    }
    cout << "angka: " << endl;
    for(auto it = this->angka.begin(); it != this->angka.end(); it++){
        cout << it->first << ": " << it->second << endl;
    }
}

Combination::~Combination(){
    delete this->combo;
}

double Combination::getValue() const{
    return 0;
}