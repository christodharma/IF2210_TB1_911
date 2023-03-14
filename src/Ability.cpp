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
        cout << "Silakan pilih pemain yang kartunya ingin Anda tukar:" << endl;
        gs.printPlayers();
        int p1;
        cin >> p1;
        cout << "Silakan pilih pemain lain yang kartunya ingin Anda tukar:" << endl;
        for (int i = 0; i < 7; i++){
            if (i != p1-1){
                cout << "   " << i+1 << ". " << gs.getPlayers()[i].getPlayerName() << endl;
            }
        }
        int p2;
        cin >> p2;
        cout << "Silakan pilih kartu kanan/kiri " << gs.getPlayers()[p1-1].getPlayerName() << endl;
        cout << "   1. Kanan" << endl;
        cout << "   2. Kiri" << endl;
        int c1;
        cin >> c1;
        cout << "Silakan pilih kartu kanan/kiri " << gs.getPlayers()[p2-1].getPlayerName() << endl;
        cout << "   1. Kanan" << endl;
        cout << "   2. Kiri" << endl;
        int c2;
        cin >> c2;
        vector<Card> res;
        if (c1 == 1){
            res.push_back(gs.getPlayers()[p1-1].getInventory()[0]);
        } else {
            res.push_back(gs.getPlayers()[p1-1].getInventory()[1]);
        }
        if (c2 == 1){
            res.push_back(gs.getPlayers()[p2-1].getInventory()[0]);
        } else {
            res.push_back(gs.getPlayers()[p2-1].getInventory()[1]);
        }
        gs.getPlayers()[p1-1].setInventory(res);
        res.clear();
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
