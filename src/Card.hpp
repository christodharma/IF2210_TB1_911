#ifndef __CARD_HPP__
#define __CARD_HPP__

#include "Valueable.hpp"
#include <iostream>
using namespace std;

class Card : public Valueable {
protected:
    Valueable* val;
    int angka;
    char warna;
public:
    //ctor, dtor
    Card(int,char);
    Card(char,int);
    ~Card();
    int getAngka();
    char getWarna();
    double getValue();
    void printCard() const;
    bool operator<(const Card& other);
    bool operator>(const Card&);
    bool operator==(const Card&);
};

#endif