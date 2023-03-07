#ifndef __CARD_HPP__
#define __CARD_HPP__

#include "Valueable.hpp"
#include <iostream>
#include <utility>
#include <string>
using namespace std;

class Card : public Valueable {
protected:
    Valueable* value;
    pair<int,char> kartu;
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
    friend ostream& operator<< (ostream& os, const Card& card);
};

#endif