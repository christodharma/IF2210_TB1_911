#ifndef __CARD_HPP__
#define __CARD_HPP__

#include "Valueable.hpp"
#include <iostream>
#include <utility> //stl-nya pair
using namespace std;

class Card : public Valueable {
protected:
    pair<char,int> kartu; //pair warna dan angka
public:
    //ctor, dtor
    Card();
    Card(int,char);
    Card(char,int);
    Card(const Card&);
    ~Card();
    char getWarna() const;
    int getAngka() const;
    double getValue() const;
    void printCard() const;
    bool operator<(const Card&);
    bool operator>(const Card&);
    bool operator==(const Card&);
    Card& operator=(const Card& other);
    friend ostream& operator<< (ostream& os, const Card& card);
};

#endif