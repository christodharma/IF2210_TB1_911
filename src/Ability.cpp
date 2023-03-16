#include "Ability.hpp"
using namespace std;

void Ability::noAbility(string input){
    cout << "Ets, tidak bisa. kamu tidak memilki Ability "<<input<<"."<< endl;
}

Ability::Ability()
{
    this->ammoAbility = 0;
    this->typeAb = "NONE";
}

string Ability::showAbility()
{
    return this->typeAb;
}

int Ability::getAmmoAbility()
{
    return 0;
}

void ReRoll::ability(string input){
    string valid = "REROLLRE-ROLL";
    if (valid.find(input) != -1){
        cout << "RE-ROLL ability activated" << endl;
    } else {
        noAbility(input);
    }
    ammoAbility--;
}
void Quadruple::ability(string input){
    string valid = "QUADRUPLE";
    if (valid.find(input) != -1){
        cout << "QUADRUPLE ability activated" << endl;
    } else {
        noAbility(input);
    }
    ammoAbility--;
}
void Quarter::ability(string input){
    string valid = "QUARTER";
    if (valid.find(input) != -1){
        cout << "QUARTER ability activated" << endl;
    } else {
        noAbility(input);
    }
    ammoAbility--;
}
void ReverseDirection::ability(string input){
    string valid = "REVERSEDIRECTION";
    if (valid.find(input) != -1){
        cout << "REVERSE ability activated" << endl;
    } else {
        noAbility(input);
    }
    ammoAbility--;
}
void SwapCard::ability(string input){
    string valid = "SWAPCARD";
    if (valid.find(input) != -1){
        cout << "SWAP ability activated" << endl;
    } else {
        noAbility(input);
    }
    ammoAbility--;
}
void Switch::ability(string input){
    string valid = "SWITCH";
    if (valid.find(input) != -1){
        cout << "SWITCH ability activated" << endl;
    } else {
        noAbility(input);
    }
    ammoAbility--;
}
void Abilityless::ability(string input, Ability* targetAb){
    string valid = "ABILITYLESS";
    if (valid.find(input) != -1){
        cout << "ABILITYLESS ability activated" << endl;
        delete targetAb;
        targetAb = new Ability;
    } else if (valid.find(input) == -1){
        noAbility(input);
    } else if (targetAb == nullptr || targetAb->showAbility() == "NONE"){
        cout << "Target tidak memiliki ability" << endl;
    } else if (targetAb->getAmmoAbility() == 0){
        cout << "Target sudah menggunakan abilitynya!" << endl;
    } else if (this->ammoAbility == 0){
        cout << "Kamu sudah menggunakan ability mu!" << endl;
    }
    ammoAbility--;
}

//ctor
ReRoll::ReRoll(){
    this->ammoAbility = 1;
    this->typeAb = "RE-ROLL";
}
Quadruple::Quadruple(){
    this->ammoAbility = 1;
    this->typeAb = "QUADRUPLE";
}
Quarter::Quarter(){
    this->ammoAbility = 1;
    this->typeAb = "QUARTER";
}
ReverseDirection::ReverseDirection(){
    this->ammoAbility = 1;
    this->typeAb = "REVERSE";
}
SwapCard::SwapCard(){
    this->ammoAbility = 1;
    this->typeAb = "SWAPCARD";
}
Switch::Switch(){
    this->ammoAbility = 1;
    this->typeAb = "SWITCH";
}
Abilityless::Abilityless(){
    this->ammoAbility = 1;
    this->typeAb = "ABILITYLESS";
}