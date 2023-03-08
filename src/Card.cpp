#include <map>
#include <vector>
#include "Card.hpp"
#include <iostream>
using namespace std;

Card::Card(int a, char w){
    this->kartu = make_pair(toupper(w),a);
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
    this->kartu = make_pair(toupper(w), a);
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

char Card::getWarna() const{
    return kartu.first;
}
int Card::getAngka() const{
    return kartu.second;
}


double Card::getValue() const{
    return this->val->getValue();
}

void Card::printCard() const{
    cout << "(" << kartu.first << "," << kartu.second << ")" << endl;
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
    return this->kartu == other.kartu;
}
ostream& operator<<(ostream& os, const Card& card){
    os << "(" << card.kartu.first << "," << card.kartu.second << " -> " << card.getValue() << ")";
}