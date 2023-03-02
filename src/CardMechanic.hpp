#ifndef __CARDMECHANIC_HPP__
#define __CARDMECHANIC_HPP__

class CardMechanic{
public:
    CardMechanic();
    virtual int getAngka();
    virtual char getWarna();
};

class Card : CardMechanic{
protected:
    int angka;
    char warna;
public:
    int getAngka();
    char getWarna();
};

#endif