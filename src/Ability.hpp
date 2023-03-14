#ifndef __ABILITY_HPP__
#define __ABILITY_HPP__

#include <string>
#include <iostream>
using namespace std;

class Ability{
public:
    Ability(){};
    virtual ~Ability(){};
    virtual void ability(string){};
    virtual char* showAbility(){};
    void noAbility(string);
};

class ReRoll : public Ability{
public:
    void ability(string);
    char* showAbility();
};

class Quadruple : public Ability {
public:
    void ability(string);
    char* showAbility();
};

class Quarter : public Ability {
public:
    void ability(string);
    char* showAbility();
};

class ReverseDirection : public Ability {
public:
    void ability(string);
    char* showAbility();
};

class SwapCard : public Ability {
public:
    void ability(string);
    char* showAbility();
};

class Switch : public Ability {
public:
    void ability(string);
    char* showAbility();
};

class Abilityless : public Ability {
public:
    void ability(string);
    char* showAbility();
};
#endif