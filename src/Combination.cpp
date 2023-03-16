#include "Combination.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <vector>


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

    this->calculate();
}

Combination::~Combination(){
}

void Combination::calculate() {
    if(isThereStraightFlush()){
        this->value = new StraightFlush(this->mapcard);
        this->type = "Straight Flush";
    }
    else if (this->isThere4Angka()) {
        int i = 1;
        while (this->mapcard[to_string(i)].getInventory().size() < 4) {
            i++;
        }
        this->value = new FourOfAKind(i);
        this->type = "Four Of A Kind";
    }
    else if (this->isThere3Angka() == 2) {
        int i = 13;
        while (this->mapcard[to_string(i)].getInventory().size() < 3) {
            i--;
        }
        this->value = new FullHouse(i);
        this->type = "Full House";
    }
    else if (this->isThere3Angka() && this->isThere2Angka()) {
        int i = 1;
        while (this->mapcard[to_string(i)].getInventory().size() < 3) {
            i++;
        }
        this->value = new FullHouse(i);
        this->type = "Full House";
    }
    else if (this->isThereFlush()) {
        this->value = new Flush(this->mapcard);
        this->type = "Flush";
    }
    else if (this->isThereStraight()) {
        this->value = new Straight(this->mapcard);
    }
    else if (this->isThere3Angka()) {
        this->value = new ThreeOfAKind(this->mapcard);
        this->type = "Three Of A Kind";
    }
    else if (this->isThereTwoPair()) {
        this->value = new TwoPair(this->mapcard);
        this->type = "Two Pair";
    }
    else if(isTherePair()){
        this->value = new Pair(this->mapcard);
        this->type = "Pair";
    }
    else{
        this->value = new HighCard(this->mapcard);
        this->type = "High Card";
    }
}

void Combination::recalculate() {
    while(true){
        Value *temp;
        if (isThereStraightFlush()) {
            temp = new StraightFlush(this->mapcard);
            if (this->getValue() != temp->getValue()) {
                this->value = temp;
                this->type = "Straight Flush";
                break;
            }
        }
        if (isThere4Angka()) {
            int i = 1;
            while (this->mapcard[to_string(i)].getInventory().size() < 4) {
                i++;
            }
            temp = new FourOfAKind(i);
            if (this->getValue() != temp->getValue()) {
                this->value = temp;
                this->type = "Four Of A Kind";
                break;
            }
        }
        if (isThere3Angka() == 2) {
            int i = 13;
            while (this->mapcard[to_string(i)].getInventory().size() < 3) {
                i--;
            }
            temp = new FullHouse(i);
            if (this->getValue() != temp->getValue()) {
                this->value = temp;
                this->type = "Full House";
                break;
            }
        }
        if (isThere3Angka() && isThere2Angka()) {
            int i = 1;
            while (this->mapcard[to_string(i)].getInventory().size() < 3) {
                i++;
            }
            temp = new FullHouse(i);
            if (this->getValue() != temp->getValue()) {
                this->value = temp;
                this->type = "Full House";
                break;
            }
        }
        if (isThereFlush()) {
            temp = new Flush(this->mapcard);
            if (this->getValue() != temp->getValue()) {
                this->value = temp;
                this->type = "Flush";
                break;
            }
        }
        if (isThereStraight()) {
            temp = new Straight(this->mapcard);
            if (this->getValue() != temp->getValue()) {
                this->value = temp;
                this->type = "Straight";
                break;
            }
        }
        if (isThere3Angka()) {
            temp = new ThreeOfAKind(this->mapcard);
            if (this->getValue() != temp->getValue()) {
                this->value = temp;
                this->type = "Three Of A Kind";
                break;
            }
        }
        if (isThereTwoPair()) {
            temp = new TwoPair(this->mapcard);
            if (this->getValue() != temp->getValue()) {
                this->value = temp;
                this->type = "Two Pair";
                break;
            }
        }
        if (isTherePair()) {
            temp = new Pair(this->mapcard);
            if (this->getValue() != temp->getValue()) {
                this->value = temp;
                this->type = "Pair";
                break;
            }
        }
        else  {
            temp = new HighCard(this->mapcard);
            if (this->getValue() != temp->getValue()) {
                this->value = temp;
                this->type = "High Card";
                break;
            }
        }
    }
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

string Combination::getType() {
    return this->type;
} // mengembalikan tipe kombinasi

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

bool Combination::isThereTwoPair(){
    int twoPair = 0;
    for (int i=1; i<=13; i++) {
        if (this->mapcard[to_string(i)].getInventory().size() == 2) {
            twoPair++;
        }
    if (twoPair == 2) {
        return true;
        }
    }
    return false;
} // cek apakah ada 2 kartu yang sama

bool Combination::isThereThreeOfAKind() {
    for (int i=1; i<=13; i++) {
        if (this->mapcard[to_string(i)].getInventory().size() == 3) {
            return true;
        }
    }
    return false;
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
    for (int i=1; i<=13; i++) {
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

bool Combination::isTherePair() {
    int count = 0;
    for(int i=13; i>0; i--){
        if (this->mapcard[to_string(i)].getInventory().size() == 2) {
            count++;
        }
    }
    if(count == 1){
        return true;
    } 
    else {
        return false;
    }
}

 // cek apakah ada 2 kartu yang sama

bool Combination::isThereStraightFlush() {
    bool affh = false;
    int count = 0;
    if (this->mapcard["M"].getInventory().size() >= 5) {
        vector<int> arr;
        for (int i = 0; i<mapcard["M"].getInventory().size(); i++) {
            arr.push_back(mapcard["M"].getInventory()[i].getAngka());
        }
        int n = sizeof(arr) / sizeof(arr[0]);
        sort(arr.begin(), arr.end());

        for (int i = 1; i<mapcard["M"].getInventory().size(); i++) {
            if (arr[i] == arr[i-1] + 1) {
                count++;
                if (count >= 4) {
                    return true;
                }
            }
            else {
                count = 0;
            }
        }
        
    } 
    else if (this->mapcard["K"].getInventory().size() >= 5) {
        vector<int> arr;
        for (int i = 0; i<mapcard["K"].getInventory().size(); i++) {
            arr.push_back(mapcard["K"].getInventory()[i].getAngka());
        }
        int n = sizeof(arr) / sizeof(arr[0]);
        sort(arr.begin(), arr.end());

        for (int i = 1; i<mapcard["K"].getInventory().size(); i++) {
            if (arr[i] == arr[i-1] + 1) {
                count++;
                if (count >= 4) {
                    return true;
                }
            }
            else {
                count = 0;
            }
        }
    } 
    else if (this->mapcard["B"].getInventory().size() >= 5) {
        vector<int> arr;
        for (int i = 0; i<mapcard["B"].getInventory().size(); i++) {
            arr.push_back(mapcard["B"].getInventory()[i].getAngka());
        }
        sort(arr.begin(), arr.end());

        for (int i = 1; i<mapcard["B"].getInventory().size(); i++) {
            if (arr[i] == arr[i-1] + 1) {
                count++;
                if (count >= 4) {
                    return true;
                }
            }
            else {
                count = 0;
            }
        }
    } 
    else if (this->mapcard["H"].getInventory().size() >= 5) {
        vector<int> arr;
        for (int i = 0; i<mapcard["H"].getInventory().size(); i++) {
            arr.push_back(mapcard["H"].getInventory()[i].getAngka());
        }
        sort(arr.begin(), arr.end()); 

        for (int i = 1; i<mapcard["H"].getInventory().size(); i++) {
            if (arr[i] == arr[i-1] + 1) {
                count++;
                if (count >= 4) {
                    return true;
                }
            }
            else {
                count = 0;
            }
        }
    } 
    else {
        return false;
    }
    return false;

}

 // cek apakah ada 5 kartu dengan angka berurutan dan warna yang sama (straight dan flush terpenuhi)