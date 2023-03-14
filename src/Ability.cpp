#include "Ability.hpp"
using namespace std;

void Ability::noAbility(string input){
    cout << "Ets, tidak bisa. kamu tidak memilki Ability "<<input<<"."<< endl;
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
void Abilityless::ability(string input){
    string valid = "ABILITYLESS";
    if (valid.find(input) != -1){
        cout << "ABILITYLESS ability activated" << endl;
    } else {
        noAbility(input);
    }
}

string ReRoll::showAbility(){
    return "RE-ROLL";
}
string Quadruple::showAbility(){
    return "QUADRUPLE";
}
string Quarter::showAbility(){
    return "QUARTER";
}
string ReverseDirection::showAbility(){
    return "REVERSE";
}
string SwapCard::showAbility(){
    return "SWAP";
}
string Switch::showAbility(){
    return "SWITCH";
}
string Abilityless::showAbility(){
    return "ABILITYLESS";
}