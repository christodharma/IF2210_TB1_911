#include "Card.hpp"

Card::Card(int a, char w){
    this->kartu = make_pair(toupper(w),a);
    // this->val = v;
    map<char,double>::iterator i = valueMap.find(w);
    if (i != valueMap.end()){
        this->value = new Value(a * 0.1 + i->second);
    }
    // else {
    //     // throw invalidCardCharInputError
    //     // this->value = 0;
    // }
}

Card::Card(char w, int a){
    this->kartu = make_pair(toupper(w), a);
    // this->val = v;
    map<char,double>::iterator i = valueMap.find(w);
    if (i != valueMap.end()){
        this->value = new Value(a * 0.1 + i->second);
    }
    // else {
    //     // throw invalidCardCharInputError
    //     // this->value = 0;
    // }
}

Card::~Card(){
    delete this->value;
}

char Card::getWarna() const{
    return kartu.first;
}
int Card::getAngka() const{
    return kartu.second;
}


double Card::getValue() const{
    return this->value->getValue();
}

void Card::printCard() const{
    cout << "(" << kartu.first << "," << kartu.second << ")" << endl;
}

bool Card::operator<(const Card& other)
{
    return this->value->getValue() < other.value->getValue();
}
bool Card::operator>(const Card& other)
{
    return this->value->getValue() > other.value->getValue();
}
bool Card::operator==(const Card& other)
{
    return this->kartu == other.kartu;
}
ostream& operator<<(ostream& os, const Card& card){
    os << "(" << card.kartu.first << "," << card.kartu.second /*<< " -> " << card.getValue()*/ << ")";
}