#ifndef __CARDMECHANIC_HPP__
#define __CARDMECHANIC_HPP__

#include <vector>
using namespace std;

class Valueable{
public:
    Valueable();
    virtual float value();
};

class Card : Valueable{
protected:
    int angka;
    char warna;
public:
    int getAngka();
    char getWarna();
    float value();
};

class Combination : Valueable{
private:
    vector<Valueable*> combo;
public:
    float value();
};

#endif