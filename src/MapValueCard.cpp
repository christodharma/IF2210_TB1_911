#include "MapValueCard.hpp"
#include "Card.hpp"
#include "InventoryHolder.hpp"
#include <iostream>
#include <string>

using namespace std;

MapValueCard::MapValueCard(){
    for (int i=0; i<13; i++) {
        this->mapcard[to_string(i)] = 0;
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
}

void MapValueCard::removeCard(Card input){
    this->mapcard[to_string(input.getAngka())]--;
}

int MapValueCard::getCardValue(string input){
    return this->mapcard[to_string(input.getAngka())];
}

void MapValueCard::showMapValueCard(){
    for (int i=0; i<13; i++){
        cout << i << " : " << this->mapcard[to_string(i)] << endl;
    }
}
