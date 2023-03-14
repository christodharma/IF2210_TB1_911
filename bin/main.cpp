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
g++ -o kompetisiKartu main.cpp ../src/Card.cpp ../src/GameState.cpp ../src/InventoryHolder.cpp ../src/Player.cpp ../src/Valueable.cpp ../src/Deck.cpp ../src/Table.cpp ../src/Ability.cpp ../src/Generics.cpp; if ($?) {./kompetisiKartu}
*/

int main(){
    bool gameIsOngoing = true;
    int playerCount = 7;
    Player* players = new Player[playerCount];
    GameState game(players, playerCount); 
    while (game.getRound()<6)
    {
        //game loop
        if (game.getRound() == 0){
            for (int i = 0; i < playerCount; i++)
            {
                players[i].drawCards(2, game.getCardDeck());
            }
            
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