#include "Ability.hpp"
using namespace std;

void Ability::noAbility(string input){
    if (this->isDisabled()) {
        cout << "Oops kartu ability " << input << "-mu telah dimatikan sebelumnya :()" << endl;
    } else if (this->isUsed()) {
        cout << "Kamu sudah menggunakan ability " << input << " sebelumnya." << endl;
    } else {
        cout << "Ets, tidak bisa. kamu tidak memilki Ability "<<input<<"."<< endl;
    }
    
}

bool Ability::isDisabled() {
    return this->disabled;
}

bool Ability::isUsed() {
    return this->used;
}

void Ability::setDisabled(bool b) {
    this->disabled = b;
}

void Ability::setUsed(bool b) {
    this->used = b;
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
}
void Quadruple::ability(string input){
    string valid = "QUADRUPLE";
    if (valid.find(input) != -1){
        cout << "QUADRUPLE ability activated" << endl;
    } else {
        noAbility(input);
    }
}
void Quarter::ability(string input){
    string valid = "QUARTER";
    if (valid.find(input) != -1){
        cout << "QUARTER ability activated" << endl;
    } else {
        noAbility(input);
    }
}
void ReverseDirection::ability(string input){
    string valid = "REVERSEDIRECTION";
    if (valid.find(input) != -1){
        cout << "REVERSE ability activated" << endl;
    } else {
        noAbility(input);
    }
}
void SwapCard::ability(string input){
    string valid = "SWAPCARD";
    if (valid.find(input) != -1){
        cout << "SWAP ability activated" << endl;
    } else {
        noAbility(input);
    }
}
void Switch::ability(string input){
    string valid = "SWITCH";
    if (valid.find(input) != -1){
        cout << "SWITCH ability activated" << endl;
    } else {
        noAbility(input);
    }
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
    }
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
