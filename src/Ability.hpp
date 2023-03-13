#ifndef __ABILITY_HPP__
#define __ABILITY_HPP__

class Ability{
public:
    Ability(){};
    virtual ~Ability(){};
    virtual void action_half();
    virtual void action_reroll();
    virtual void action_quadruple();
    virtual void action_quarter();
    virtual void action_reverse();
    virtual void action_swapcard();
    virtual void action_switch();
    virtual void action_abilityless();
    void noAbility();
};

class ReRoll : Ability{
public:
    void action_half();
    void action_reroll();
    void action_quadruple();
    void action_quarter();
    void action_reverse();
    void action_swapcard();
    void action_switch();
    void action_abilityless();
};

class Quadruple : Ability {
public:
    void action_half();
    void action_reroll();
    void action_quadruple();
    void action_quarter();
    void action_reverse();
    void action_swapcard();
    void action_switch();
    void action_abilityless();

};

class Quarter : Ability {
public:
    void action_half();
    void action_reroll();
    void action_quadruple();
    void action_quarter();
    void action_reverse();
    void action_swapcard();
    void action_switch();
    void action_abilityless();

};

class ReverseDirection : Ability {
public:
    void action_half();
    void action_reroll();
    void action_quadruple();
    void action_quarter();
    void action_reverse();
    void action_swapcard();
    void action_switch();
    void action_abilityless();
};

class SwapCard : Ability {
public:
    void action_half();
    void action_reroll();
    void action_quadruple();
    void action_quarter();
    void action_reverse();
    void action_swapcard();
    void action_switch();
    void action_abilityless();
};

class Switch : Ability {
public:
    void action_half();
    void action_reroll();
    void action_quadruple();
    void action_quarter();
    void action_reverse();
    void action_swapcard();
    void action_switch();
    void action_abilityless();
};

class Abilityless : Ability {
public:
    void action_half();
    void action_reroll();
    void action_quadruple();
    void action_quarter();
    void action_reverse();
    void action_swapcard();
    void action_switch();
    void action_abilityless();
};
#endif