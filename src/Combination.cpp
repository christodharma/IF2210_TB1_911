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
}

Combination::~Combination(){
    delete this->combo;
}