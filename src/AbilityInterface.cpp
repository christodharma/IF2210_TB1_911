#include "AbilityInterface.hpp"

AbilityInterface::AbilityInterface() {
    this->ability = NULL;
    this->gameState = NULL;
}

AbilityInterface::AbilityInterface(Ability* a, GameState& g, Player& p) {
    this->ability = a;
    this->gameState = &g;
    if(a->showAbility() == "NONE") {
        cout << "Ability not found" << endl;
    }
    else if (a->showAbility() == "SWITCH") {
        cout << p.getPlayerName() << " melakukan switch!" << endl;
        cout << "Kartumu sekarang adalah:" << endl;
        p.getInventory()[0].printCard();
        p.getInventory()[1].printCard();
        cout << "Silakan pilih pemain yang kartunya ingin Anda tukar:" << endl;
        g.printPlayers();
        int input;
        cin >> input;
        vector<Card> temp;
        temp.push_back(p.getInventory()[0]);
        temp.push_back(p.getInventory()[1]);
        p.setPlayerInventory(g.getPlayer(input-1).getInventory());
        g.getPlayer(input-1).setPlayerInventory(temp);
        cout << "Kedua kartu " << p.getPlayerName() << " telah ditukar dengan " << g.getPlayer(input-1).getPlayerName() << endl;
        cout << "Kartumu sekarang adalah:" << endl;
        p.getInventory()[0].printCard();
        p.getInventory()[1].printCard();
    }
}

AbilityInterface::~AbilityInterface() {
    delete this->ability;
    delete this->gameState;
}

void AbilityInterface::setInterface(Ability* a, GameState& g, Player& p) {
    this->ability = a;
    this->gameState = &g;
}
