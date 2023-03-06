#ifndef __ABILITY_HPP__
#define __ABILITY_HPP__

class Ability{
protected:
    int abilityType;    //might need map
public:
    Ability();
    virtual ~Ability(){};
    int getType();
};

class ReRoll : Ability{
// protected:
//     Player* owner;   //masi gatau
private:
    int abilityType = 1;
};

class Quadruple : Ability {
private:
    int abilityType = 2;
};

class Quarter : Ability {
private:
    int abilityType = 3;
};

class ReverseDirection : Ability {
private:
    int abilityType = 4;
};

class SwapCard : Ability {
private:
    int abilityType = 5;
};

class Switch : Ability {
private:
    int abilityType = 6;
};

class Abilityless : Ability {
private:
    int abilityType = 7;
};
#endif