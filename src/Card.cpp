#include "Card.hpp"

Card::Card(int a, char w){
    kartu = make_pair(a,toupper(w));
    // this->value = v;
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
    kartu = make_pair(a,toupper(w));
    // this->value = v;
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

int Card::getAngka(){
    return kartu.first;
}

char Card::getWarna(){
    return kartu.second;
}

double Card::getValue(){
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
    return this->value->getValue() == other.value->getValue();
}
ostream& operator<<(ostream& os, const Card& card){
    os << "(" << card.kartu.first << "," << card.kartu.second << ")";
}