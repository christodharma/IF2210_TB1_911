#ifndef __ABILITY_HPP__
#define __ABILITY_HPP__

class Ability{
public:
    virtual int getType();
};

class ReRoll : Ability{
private:
    int abilityType = 1;
public:
    int getType();
};

class Quadruple : Ability {
private:
    int abilityType = 2;
public:
    int getType();
};

class Quarter : Ability {
private:
    int abilityType = 3;
public:
    int getType();
};

class ReverseDirection : Ability {
private:
    int abilityType = 4;
public:
    int getType();
};

class SwapCard : Ability {
private:
    int abilityType = 5;
public:
    int getType();
};

class Switch : Ability {
private:
    int abilityType = 6;
    int getType();
};

class Abilityless : Ability {
private:
    int abilityType = 7;
public:
    int getType();
};
#endif