#include "MapValueCard.hpp"
#include <iostream>
#include <string>

using namespace std;

MapValueCard::MapValueCard(){
    for (int i=0; i<13; i++) {
        this->mapcard[to_string(i)] = 0;
    }
    for (int i=0; i<4; i++) {
        this->cardcolor[i] = 0;
    }    
}

MapValueCard::~MapValueCard(){
}

void MapValueCard::setMap(CardInventory hand, CardInventory table){
    for (int i=0; i<hand.getInventory().size(); i++){
        this->addCard(hand.getInventory()[i]);
    }
    for (int i=0; i<table.getInventory().size(); i++){
        this->addCard(table.getInventory()[i]);
    }
}

void MapValueCard::addCard(Card input){
    this->mapcard[to_string(input.getAngka())]++;
    // cout << this->mapcard[to_string(input.getAngka())] << endl;
    this->cardcolor[input.getWarna()]++;
}

void MapValueCard::removeCard(Card input){
    this->mapcard[to_string(input.getAngka())]--;
    this->cardcolor[input.getWarna()]--;
}

int MapValueCard::getCardValue(string input){
    return this->mapcard[input];
}

int MapValueCard::getCardColor(char input){
    return this->cardcolor[input];
}

void MapValueCard::showMapValueCard(){
    for (int i=0; i<13; i++){
        cout << i << " : " << this->mapcard[to_string(i)] << endl;
    }
    cout << "Merah : " << this->cardcolor['M'] << endl;
    cout << "Kuning : " << this->cardcolor['K'] << endl;
    cout << "Hijau : " << this->cardcolor['H'] << endl;
    cout << "Biru : " << this->cardcolor['B'] << endl;
}
