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

    if(isThereStraightFlush()){
        cout << "YEY STRAIGHT FLUSH" << endl;
        this->value = new StraightFlush(this->mapcard);
        cout << this->getValue() << endl;
    }
    else if (this->isThere4Angka()) {
        cout << "Four Of A Kind" << endl;
        int i = 1;
        while (this->mapcard[to_string(i)].getInventory().size() < 4) {
            i++;
        }
        this->value = new FourOfAKind(i);
        cout << this->getValue() << endl; 
    }
    else if (this->isThere3Angka() == 2) {
        cout << "Full House" << endl;
        int i = 13;
        while (this->mapcard[to_string(i)].getInventory().size() < 3) {
            i--;
        }
        this->value = new FullHouse(i);
        cout << this->getValue() << endl;
    }
    else if (this->isThere3Angka() && this->isThere2Angka()) {
        cout << "Full House" << endl;
        int i = 1;
        while (this->mapcard[to_string(i)].getInventory().size() < 3) {
            i++;
        }
        this->value = new FullHouse(i);
        cout << this->getValue() << endl;
    }
    else if (this->isThereFlush()) {
        cout << "YEY FLUSH" << endl;
        this->value = new Flush(this->mapcard);
        cout << this->getValue() << endl;
    }
    else if (this->isThereStraight()) {
        cout << "YEY STRAIGHT" << endl;
        this->value = new Straight(this->mapcard);
        cout << this->getValue() << endl;
    }
    else if (this->isThere3Angka()) {
        cout << "Three Of A Kind" << endl;
        this->value = new ThreeOfAKind(this->mapcard);
        cout << this->getValue() << endl;
    }
    else if (this->isThereTwoPair()) {
        cout << "Two Pair" << endl;
        this->value = new TwoPair(this->mapcard);
        cout << this->getValue() << endl;
    }
    else if(isTherePair()){
        cout << "YEY PAIR" << endl;
        this->value = new Pair(this->mapcard);
        cout << this->getValue() << endl;
    }
    else{
        cout << "YEY HIGH CARD" << endl;
        this->value = new HighCard(this->mapcard);
        cout << this->getValue() << endl;
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
    string m(1, 'M');
    string k(1, 'K');
    string b(1, 'B');
    string h(1, 'H');
    if (this->mapcard[m].getInventory().size() >= 5) {
        int arr[mapcard[m].getInventory().size()];
        for (int i = 0; i<mapcard[m].getInventory().size(); i++) {
            arr[i] = mapcard[m].getInventory()[i].getAngka();
        }
        int n = sizeof(arr) / sizeof(arr[0]);
        sort(arr, arr + n);

        for (int i = 1; i<mapcard[m].getInventory().size(); i++) {
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
    else if (this->mapcard[k].getInventory().size() >= 5) {
        int arr[mapcard[k].getInventory().size()];
        for (int i = 0; i<mapcard[k].getInventory().size(); i++) {
            arr[i] = mapcard[k].getInventory()[i].getAngka();
        }
        int n = sizeof(arr) / sizeof(arr[0]);
        sort(arr, arr + n);

        for (int i = 1; i<mapcard[k].getInventory().size(); i++) {
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
    else if (this->mapcard[b].getInventory().size() >= 5) {
        int arr[mapcard[b].getInventory().size()];
        for (int i = 0; i<mapcard[b].getInventory().size(); i++) {
            arr[i] = mapcard[b].getInventory()[i].getAngka();
        }
        int n = sizeof(arr) / sizeof(arr[0]);
        sort(arr, arr + n);

        for (int i = 1; i<mapcard[b].getInventory().size(); i++) {
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
    else if (this->mapcard[h].getInventory().size() >= 5) {
        int arr[mapcard[h].getInventory().size()];
        for (int i = 0; i<mapcard[h].getInventory().size(); i++) {
            arr[i] = mapcard[h].getInventory()[i].getAngka();
        }
        int n = sizeof(arr) / sizeof(arr[0]);
        sort(arr, arr + n);    

        for (int i = 1; i<mapcard[h].getInventory().size(); i++) {
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