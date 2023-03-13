#include "MapCard.hpp"
#include <iostream>
#include <string>

using namespace std;

MapCard::MapCard(){

}

MapCard::MapCard(CardInventory hand, CardInventory table){
    // tambah semua kartu yang ada di hand dan table ke comb
    for (int i=0; i<hand.getInventory().size(); i++){
        this->hold += hand.getInventory()[i];
    }
    for (int i=0; i<table.getInventory().size(); i++){
        this->hold += table.getInventory()[i];
    }

    // proses mapping
    for (int i=0; i<hand.getInventory().size(); i++){
        this->addCard(hand.getInventory()[i]);
    }
    for (int i=0; i<table.getInventory().size(); i++){
        this->addCard(table.getInventory()[i]);
    }
}

MapCard::~MapCard(){
}

void MapCard::setMap(CardInventory hand, CardInventory table){
    for (int i=0; i<hand.getInventory().size(); i++){
        this->addCard(hand.getInventory()[i]);
    }
    for (int i=0; i<table.getInventory().size(); i++){
        this->addCard(table.getInventory()[i]);
    }
}

CardInventory MapCard::getHold(){
    return this->hold;
}

void MapCard::addCard(Card input){
    this->cardangka[to_string(input.getAngka())]++;
    this->cardcolor[input.getWarna()]++;
}

void MapCard::removeCard(Card input){
    this->cardangka[to_string(input.getAngka())]--;
    this->cardcolor[input.getWarna()]--;
}

int MapCard::getCardAngka(string input){
    return this->cardangka[input];
}

int MapCard::getCardColor(char input){
    return this->cardcolor[input];
}

void MapCard::showMapCard(){
    cout << "Map Angka" << endl;
    for (auto it = this->cardangka.begin(); it != this->cardangka.end(); ++it){
        cout << it->first << " : " << it->second << endl;
    }
    cout << "Map Warna" << endl;
    for (auto it = this->cardcolor.begin(); it != this->cardcolor.end(); ++it){
        cout << it->first << " : " << it->second << endl;
    }
}
