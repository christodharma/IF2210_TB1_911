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
    }
    for (int i=0; i<table.getInventory().size(); i++){
        this->addCard(table.getInventory()[i]);
    }
}

void Combination::addCard(Card input){
    this->mapcard[to_string(input.getAngka())]++;
    // cout << this->mapcard[to_string(input.getAngka())] << endl;
    this->cardcolor[input.getWarna()]++;
}

void Combination::removeCard(Card input){
    this->mapcard[to_string(input.getAngka())]--;
    this->cardcolor[input.getWarna()]--;
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
