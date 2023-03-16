#include "Ability.hpp"
using namespace std;

void Ability::noAbility(string input){
    cout << "Ets, tidak bisa. kamu tidak memilki Ability "<<input<<"."<< endl;
}

string Ability::showAbility(){
    return "NONE";
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
}
Quadruple::Quadruple(){
    this->ammoAbility = 1;
}
Quarter::Quarter(){
    this->ammoAbility = 1;
}
ReverseDirection::ReverseDirection(){
    this->ammoAbility = 1;
}
SwapCard::SwapCard(){
    this->ammoAbility = 1;
}
Switch::Switch(){
    this->ammoAbility = 1;
}
Abilityless::Abilityless(){
    this->ammoAbility = 1;
}

string ReRoll::showAbility(){
    string valid = "RE-ROLL";
    return valid;
}
string Quadruple::showAbility(){
    string valid = "QUADRUPLE";
    return valid;
}
string Quarter::showAbility(){
    string valid = "QUARTER";
    return valid;
}
string ReverseDirection::showAbility(){
    string valid = "REVERSE";
    return valid;
}
string SwapCard::showAbility(){
    string valid = "SWAP";
    return valid;
}
string Switch::showAbility(){
    string valid = "SWITCH";
    return valid;
}
string Abilityless::showAbility(){
    string valid = "ABILITYLESS";
    return valid;
}
