#include "Ability.hpp"
#include <iostream>
using namespace std;

Ability::Ability(){}

Ability::~Ability(){}

void Ability::noAbility(){
    cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability";
}

void ReRoll::action_half(){
    noAbility();cout << "HALF" << endl;
};
void ReRoll::action_reroll(){
    cout << "Ability Re-Roll!" << endl;
};
void ReRoll::action_quadruple(){
    noAbility();cout << "QUADRUPLE" << endl;
};
void ReRoll::action_quarter(){
    noAbility();cout << "QUARTER" << endl;
};
void ReRoll::action_reverse(){
    noAbility();cout << "REVERSE" << endl;
};
void ReRoll::action_swapcard(){
    noAbility();cout << "SWAPCARD" << endl;
};
void ReRoll::action_switch(){
    noAbility();cout << "SWIICH" << endl;
};
void ReRoll::action_abilityless(){
    noAbility();cout << "ABILITYLESS" << endl;
};

void Quadruple::action_half(){};
void Quadruple::action_reroll(){};
void Quadruple::action_quadruple(){};
void Quadruple::action_quarter(){};
void Quadruple::action_reverse(){};
void Quadruple::action_swapcard(){};
void Quadruple::action_switch(){};
void Quadruple::action_abilityless(){};

void Quarter::action_half(){};
void Quarter::action_reroll(){};
void Quarter::action_quadruple(){};
void Quarter::action_quarter(){};
void Quarter::action_reverse(){};
void Quarter::action_swapcard(){};
void Quarter::action_switch(){};
void Quarter::action_abilityless(){};

void ReverseDirection::action_half(){};
void ReverseDirection::action_reroll(){};
void ReverseDirection::action_quadruple(){};
void ReverseDirection::action_quarter(){};
void ReverseDirection::action_reverse(){};
void ReverseDirection::action_swapcard(){};
void ReverseDirection::action_switch(){};
void ReverseDirection::action_abilityless(){};

void Switch::action_half(){};
void Switch::action_reroll(){};
void Switch::action_quadruple(){};
void Switch::action_quarter(){};
void Switch::action_reverse(){};
void Switch::action_swapcard(){};
void Switch::action_switch(){};
void Switch::action_abilityless(){};

void Abilityless::action_half(){};
void Abilityless::action_reroll(){};
void Abilityless::action_quadruple(){};
void Abilityless::action_quarter(){};
void Abilityless::action_reverse(){};
void Abilityless::action_swapcard(){};
void Abilityless::action_switch(){};
void Abilityless::action_abilityless(){};