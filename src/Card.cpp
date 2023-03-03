#include <map>
#include <vector>
#include "Card.hpp"
#include <iostream>
using namespace std;

Card::Card(){
    this->angka = 0;
    this->warna = 'O';
    this->value = 0;
}

Card::Card(int a, char w){
    this->angka = a;
    this->warna = w;
    map<char,float>::iterator i = valueMap.find('w');
    if (i != valueMap.end()){
        this->value = a * 0.1 + i->second;
    }
    else {
        // throw invalidCardCharInputError
        this->value = 0;
    }
}

int Card::getAngka(){
    return this->angka;
}

char Card::getWarna(){
    return this->warna;
}

float Card::getValue(){
    return this->value;
}

void Card::printCard() const{
    cout << "(" << this->angka << "," << this->warna << ")" << endl;
}