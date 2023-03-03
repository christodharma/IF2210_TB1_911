#ifndef __CARD_HPP__
#define __CARD_HPP__

#include "Valueable.hpp"
#include <iostream>
using namespace std;

class Card : Valueable{
protected:
    int angka;
    char warna;
public:
    Card();
    Card(int,char);
    int getAngka();
    char getWarna();
    float getValue();
    void printCard() const;
};

#endif