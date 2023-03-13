#include <vector>
#include <map>
#include "Valueable.hpp"
#include "Card.hpp"
using namespace std;

map<char,double> Valueable::valueMap = {
    {'H', 0.0},
    {'B', 0.03},
    {'K', 0.06},
    {'M', 0.09},
    {'h', 0.0},
    {'b', 0.03},
    {'k', 0.06},
    {'m', 0.09},
};
//dictionary warna, hanya kapital karena toupper di Card.cpp
map<char,string> Valueable::dictWarna = {
    {'H', "Hijau"},
    {'B', "Biru"},
    {'K', "Kuning"},
    {'M', "Merah"}
};

Value::Value(double x)
{
    this->value = x;
}
    // map<char,double>::iterator i = valueMap.find(x.getWarna());
    // if (i != valueMap.end()){
    //     this->value = x.getAngka() * 0.1 + i->second;
    // }
    // else {
    //     // throw invalidCardCharInputError
    //     this->value = 0;
    // }

double Value::getValue() const{
    return this->value;
}