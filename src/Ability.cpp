#include "Ability.hpp"
using namespace std;

void Ability::noAbility(string input){
    cout << "Ets, tidak bisa. kamu tidak memilki Ability "<<input<<"."<< endl;
}

void ReRoll::ability(string input, GameState& gs){
    string valid = "REROLLRE-ROLL";
    if (valid.find(input) != -1){

        cout << "RE-ROLL ability activated" << endl;
    } else {
        noAbility(input);
    }
}
void Quadruple::ability(string input, GameState& gs){
    string valid = "QUADRUPLE";
    if (valid.find(input) != -1){
        gs.setPrize(4*gs.getPrize());
        cout << "QUADRUPLE ability activated" << endl;
    } else {
        noAbility(input);
    }
}
void Quarter::ability(string input, GameState& gs){
    string valid = "QUARTER";
    if (valid.find(input) != -1){
        gs.setPrize(gs.getPrize()/4);
        cout << "QUARTER ability activated" << endl;
    } else {
        noAbility(input);
    }
}
void ReverseDirection::ability(string input, GameState& gs){
    string valid = "REVERSEDIRECTION";
    if (valid.find(input) != -1){
        cout << "REVERSE ability activated" << endl;
    } else {
        noAbility(input);
    }
}
void SwapCard::ability(string input, GameState& gs, Player& p){
    string valid = "SWAPCARD";
    if (valid.find(input) != -1){
        cout << "Ability SWAP digunakan" << endl;
        cout << "Silakan pilih pemain yang kartunya ingin Anda tukar:";
        gs.printPlayers();
        int input;
        cin >> input;
        Player& p2 = gs.getPlayer(input);
        cout << "Silakan pilih kartu kanan/kiri" << p2.getPlayerName() << endl;
        cout << "   1. Kanan" << endl;
        cout << "   2. Kiri" << endl;
        int input2;
        cin >> input2;
        Card c1 = p.getInventory()[0];
        Card c2 = p.getInventory()[1];
    

    } else {
        noAbility(input);
    }
}
void Switch::ability(string input, GameState& gs){
    string valid = "SWITCH";
    if (valid.find(input) != -1){
        cout << "SWITCH ability activated" << endl;
    } else {
        noAbility(input);
    }
}
void Abilityless::ability(string input, GameState& gs){
    string valid = "ABILITYLESS";
    if (valid.find(input) != -1){
        gs.printPlayers();
        cout << "Pilih player yang akan dihapus ability-nya: ";
        string input;
        cin >> input;

        cout << "ABILITYLESS ability activated" << endl;
    } else {
        noAbility(input);
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
