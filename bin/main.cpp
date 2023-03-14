#include "../src/Card.hpp"
#include "../src/GameState.hpp"
#include "../src/InventoryHolder.hpp"
#include "../src/Player.hpp"
#include "../src/Valueable.hpp"
#include "../src/Deck.hpp"
#include "../src/Table.hpp"
#include "../src/Ability.hpp"
#include <iostream>
using namespace std;
/*
cd bin/driver
g++ -o kompetisiKartu main.cpp ../src/Card.cpp ../src/GameState.cpp ../src/InventoryHolder.cpp ../src/Player.cpp ../src/Valueable.cpp ../src/Deck.cpp ../src/Table.cpp ../src/Ability.cpp; if ($?) {./kompetisiKartu}
*/

int main(){
    bool gameIsOngoing = true;
    int playerCount = 7;
    cout << "How many players? (Default 7)" << endl;
    cin >> playerCount;
    Player* players = new Player[playerCount];
    GameState game(players, playerCount); 
    while (gameIsOngoing)
    {
        //game loop
        if (game.getRound() == 0){
            game.dealCards(2);
            for (int i = 0; i < playerCount; i++)
            {
                players[i].showPlayerInfo();
            }
        } else if (game.getRound() == 1){
            game.dealAbility();
            for (int i = 0; i < playerCount; i++)
            {
                players[i].showPlayerInfo();
            }
        } else if (game.getRound() == 5){
            gameIsOngoing = false;
        }
        game.playRound();
        game.nextRound();
    }
    cin.ignore();
    return 0;
}