#include "Card.hpp"

Card::Card(){}

Card::Card(int a, char w){
    this->kartu = make_pair(toupper(w),a);
}

Card::Card(char w, int a){
    this->kartu = make_pair(toupper(w), a);
}
Card::Card(const Card &other)
{
    this->kartu = make_pair(toupper(other.kartu.first), other.kartu.second);
}
Card::~Card()
{
}

char Card::getWarna() const{
    return kartu.first;
}
int Card::getAngka() const{
    return kartu.second;
}

double Card::getValue() const{
    map<char,double>::iterator i = valueMap.find(this->kartu.first);
    if (i != valueMap.end()){
        Valueable* valptr = new Value(this->kartu.second * 0.1 + i->second);
        double val = valptr->getValue();
        delete valptr;
        return val;
    }
    else {
        // throw invalidCardCharInputError
        return 0;
    }
}

void Card::printCard() const{
    //find char kartu.first on dictWarna
    map<char,string>::iterator i = dictWarna.find(this->kartu.first);
    cout << "(" << i->second << "," << kartu.second << ")" << endl;
}

bool Card::operator<(const Card& other)
{
    return this->getValue() < other.getValue();
}
bool Card::operator>(const Card& other)
{
    return this->getValue() > other.getValue();
}
bool Card::operator==(const Card& other)
{
    return this->kartu == other.kartu;
}
Card &Card::operator=(const Card &other)
{
    this->kartu = other.kartu;
    return *this;
}
ostream &operator<<(ostream &os, const Card &card)
{
    //find char kartu.first on dictWarna
    map<char,string>::iterator i = card.dictWarna.find(card.kartu.first);
    os << card.kartu.second<< " (" << i->second << ")" /*<< " -> " << card.getValue()*/;
    return os;
}