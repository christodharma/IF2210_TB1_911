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
    void noAbility(string);
};

class ReRoll : public Ability{
public:
    void ability(string);
};

class Quadruple : public Ability {
public:
    void ability(string);
};

class Quarter : public Ability {
public:
    void ability(string);
};

class ReverseDirection : public Ability {
public:
    void ability(string);
};

class SwapCard : public Ability {
public:
    void ability(string);
};

class Switch : public Ability {
public:
    void ability(string);
};

class Abilityless : public Ability {
public:
    void ability(string);
};
#endif