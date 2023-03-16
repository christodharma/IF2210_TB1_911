#ifndef __ABILITY_HPP__
#define __ABILITY_HPP__

#include <string>
#include <iostream>
using namespace std;

class Ability{
protected:
    int ammoAbility = 0;
    string typeAb;
public:
    Ability();
    virtual ~Ability(){};
    virtual void ability(string){};
    virtual int getAmmoAbility();
    string showAbility();
    void noAbility(string);
};

class ReRoll : public Ability{
public:
    ReRoll();
    void ability(string);
};

class Quadruple : public Ability {
public:
    Quadruple();
    void ability(string);
};

class Quarter : public Ability {
public:
    Quarter();
    void ability(string);
};

class ReverseDirection : public Ability {
public:
    ReverseDirection();
    void ability(string);
};

class SwapCard : public Ability {
public:
    SwapCard();
    void ability(string);
};

class Switch : public Ability {
public:
    Switch();
    void ability(string);
};

class Abilityless : public Ability {
public:
    Abilityless();
    void ability(string, Ability*);
};
#endif