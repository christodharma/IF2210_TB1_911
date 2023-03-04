#include <map>
#include <vector>
#include "Card.hpp"
#include <iostream>
using namespace std;

Card::Card(int a, char w){
    this->angka = a;
    this->warna = toupper(w);
    // this->val = v;
    map<char,double>::iterator i = valueMap.find(w);
    if (i != valueMap.end()){
        this->val = new Value(a * 0.1 + i->second);
    }
    // else {
    //     // throw invalidCardCharInputError
    //     // this->val = 0;
    // }
}

Card::Card(char w, int a){
    this->angka = a;
    this->warna = toupper(w);
    // this->val = v;
    map<char,double>::iterator i = valueMap.find(w);
    if (i != valueMap.end()){
        this->val = new Value(a * 0.1 + i->second);
    }
    // else {
    //     // throw invalidCardCharInputError
    //     // this->val = 0;
    // }
}

Card::~Card(){
    delete val;
}

int Card::getAngka(){
    return this->angka;
}

char Card::getWarna(){
    return this->warna;
}

double Card::getValue(){
    return this->val->getValue();
}

void Card::printCard() const{
    cout << "(" << this->angka << "," << this->warna << ")" << endl;
}

bool Card::operator<(const Card& other)
{
    return this->val->getValue() < other.val->getValue();
}
bool Card::operator>(const Card& other)
{
    return this->val->getValue() > other.val->getValue();
}
bool Card::operator==(const Card& other)
{
    return this->val->getValue() == other.val->getValue();
}