#ifndef __CARD_HPP__
#define __CARD_HPP__

#include "Valueable.hpp"
#include <iostream>
// #include <utility> //stl-nya pair
using namespace std;

class Card : public Valueable {
protected:
    Valueable* val;
    /*implementasi pair STL aja? pair<int,char> atau pair<int,string>*/
    char warna;
    int angka;
public:
    //ctor, dtor
    Card(int,char);
    Card(char,int);
    ~Card();
    int getAngka();
    char getWarna();
    double getValue();
    void printCard() const;
    bool operator<(const Card&);
    bool operator>(const Card&);
    bool operator==(const Card&);
};

#endif