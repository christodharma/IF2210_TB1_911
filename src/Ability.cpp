#include "Ability.hpp"
#include <iostream>
using namespace std;

Ability::Ability(){}

Ability::~Ability(){}

void Ability::noAbility(string x){
    cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability " << x << endl;
}

void ReRoll::action_half(){
    noAbility("HALF");
};
void ReRoll::action_reroll(){
    cout << "Ability Re-Roll!" << endl;
};
void ReRoll::action_quadruple(){
    noAbility("QUADRUPLE");
};
void ReRoll::action_quarter(){
    noAbility("QUARTER");
};
void ReRoll::action_reverse(){
    noAbility("REVERSE");
};
void ReRoll::action_swapcard(){
    noAbility("SWAPCARD");
};
void ReRoll::action_switch(){
    noAbility("SWITCH");
};
void ReRoll::action_abilityless(){
    noAbility("ABILITYLESS");
};

void Quadruple::action_half(){
    noAbility("HALF");
};
void Quadruple::action_reroll(){
    
};
void Quadruple::action_quadruple(){
    cout << "Ability Quadruple!" << endl;
};
void Quadruple::action_quarter(){
    noAbility("QUARTER");
};
void Quadruple::action_reverse(){
    noAbility("REVERSE");
};
void Quadruple::action_swapcard(){
    noAbility("SWAPCARD");
};
void Quadruple::action_switch(){
    noAbility("SWITCH");
};
void Quadruple::action_abilityless(){
    noAbility("ABILITYLESS");
};

void Quarter::action_half(){
    noAbility("HALF");
};
void Quarter::action_reroll(){
    noAbility("REROLL");
};
void Quarter::action_quadruple(){
    noAbility("QUADRUPLE");
};
void Quarter::action_quarter(){
    cout << "Ability Quarter!" << endl;
};
void Quarter::action_reverse(){
    noAbility("REVERSE");
};
void Quarter::action_swapcard(){
    noAbility("SWAPCARD");
};
void Quarter::action_switch(){
    noAbility("SWITCH");
};
void Quarter::action_abilityless(){
    noAbility("ABILITYLESS");
};

void ReverseDirection::action_half(){
    noAbility("HALF");
};
void ReverseDirection::action_reroll(){
    noAbility("REROLL");
};
void ReverseDirection::action_quadruple(){
    noAbility("QUADRUPLE");
};
void ReverseDirection::action_quarter(){
    noAbility("QUARTER");
};
void ReverseDirection::action_reverse(){
    cout << "Ability Reverse Direction!" << endl;
};
void ReverseDirection::action_swapcard(){
    noAbility("SWAPCARD");
};
void ReverseDirection::action_switch(){
    noAbility("SWITCH");
};
void ReverseDirection::action_abilityless(){
    noAbility("ABILITYLESS");
};

void Switch::action_half(){
    noAbility("HALF");
};
void Switch::action_reroll(){
    noAbility("REROLL");
};
void Switch::action_quadruple(){
    noAbility("QUADRUPLE");
};
void Switch::action_quarter(){
    noAbility("QUARTER");
};
void Switch::action_reverse(){
    noAbility("REVERSE");
};
void Switch::action_swapcard(){
    noAbility("SWAPCARD");
};
void Switch::action_switch(){
    cout << "Ability Switch!" << endl;
};
void Switch::action_abilityless(){
    noAbility("ABILITYLESS");
};

void Abilityless::action_half(){ 
    noAbility("HALF");
};
void Abilityless::action_reroll(){
    noAbility("REROLL");
};
void Abilityless::action_quadruple(){
    noAbility("QUADRUPLE");
};
void Abilityless::action_quarter(){
    noAbility("QUARTER");
};
void Abilityless::action_reverse(){
    noAbility("REVERSE");
};
void Abilityless::action_swapcard(){
    noAbility("SWAPCARD");
};
void Abilityless::action_switch(){
    noAbility("SWITCH");
};
void Abilityless::action_abilityless(){
    cout << "Ability Abilityless!" << endl;
};