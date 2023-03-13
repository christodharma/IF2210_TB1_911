// #include "../src/Ability.hpp"
#include "../src/Card.hpp"
#include "../src/GameState.hpp"
#include "../src/InventoryHolder.hpp"
#include "../src/Player.hpp"
#include "../src/Valueable.hpp"
#include "../src/Deck.hpp"
#include "../src/Table.hpp"
#include <iostream>
#include <string>
using namespace std;
/*
cd bin/driver
g++ -o kompetisiKartu main.cpp ../src/Card.cpp ../src/GameState.cpp ../src/InventoryHolder.cpp ../src/Player.cpp ../src/Valueable.cpp ../src/Deck.cpp ../src/Table.cpp; if ($?) {./kompetisiKartu}
../src/Ability.cpp
*/

int main(){
    bool gameIsOngoing = true;
    int playerCount = 7;
    cout << "How many players? (Default 7)" << endl;
    cin >> playerCount;
    Player* players = new Player[playerCount];
    while (gameIsOngoing)
    {
        //game loop
        GameState game(players, playerCount); //round 1
        game.nextRound(); //round 2
        game.nextRound(); //round 3
        game.nextRound(); //round 4
        game.nextRound(); //round 5
        game.nextRound(); //round 6
        gameIsOngoing = false;
    }
    cin.ignore();
    return 0;
}