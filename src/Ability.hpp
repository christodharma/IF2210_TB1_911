#ifndef __ABILITY_HPP__
#define __ABILITY_HPP__

#include "GameState.hpp"
#include <string>
#include <iostream>
using namespace std;

class Ability{
public:
    Ability(){};
    virtual ~Ability(){};
    virtual void ability(string, GameState&){};
    virtual string showAbility(){return "";};
    void noAbility(string);
};

class ReRoll : public Ability{
public:
    void ability(string, GameState&);
    string showAbility();
};

class Quadruple : public Ability {
public:
    void ability(string, GameState&);
    string showAbility();
};

class Quarter : public Ability {
public:
    void ability(string, GameState&);
    string showAbility();
};

class ReverseDirection : public Ability {
public:
    void ability(string, GameState&);
    string showAbility();
};

class SwapCard : public Ability {
public:
    void ability(string, GameState&, Player&);
    string showAbility();
};

class Switch : public Ability {
public:
    void ability(string, GameState&);
    string showAbility();
};

class Abilityless : public Ability {
public:
    void ability(string, GameState&);
    string showAbility();
};
#endif