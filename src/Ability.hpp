#ifndef __ABILITY_HPP__
#define __ABILITY_HPP__

#include <string>
#include <iostream>
using namespace std;

class Ability{
protected:
    int ammoAbility = 0;
public:
    Ability(){};
    virtual ~Ability(){};
    virtual void ability(string){};
    virtual string showAbility();
    virtual int getAmmoAbility();
    void noAbility(string);
};

class ReRoll : public Ability{
public:
    ReRoll();
    void ability(string);
    string showAbility();
};

class Quadruple : public Ability {
public:
    Quadruple();
    void ability(string);
    string showAbility();
};

class Quarter : public Ability {
public:
    Quarter();
    void ability(string);
    string showAbility();
};

class ReverseDirection : public Ability {
public:
    ReverseDirection();
    void ability(string);
    string showAbility();
};

class SwapCard : public Ability {
public:
    SwapCard();
    void ability(string);
    string showAbility();
};

class Switch : public Ability {
public:
    Switch();
    void ability(string);
    string showAbility();
};

class Abilityless : public Ability {
public:
    Abilityless();
    void ability(string, Ability*);
    string showAbility();
};
#endif