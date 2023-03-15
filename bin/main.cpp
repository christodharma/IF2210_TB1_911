#include "../src/Card.hpp"
#include "../src/GameState.hpp"
#include "../src/InventoryHolder.hpp"
#include "../src/Player.hpp"
#include "../src/Valueable.hpp"
#include "../src/Deck.hpp"
#include "../src/Table.hpp"
#include "../src/Ability.hpp"
#include "../src/GameManager.hpp"
#include "../src/Generics.hpp"
#include "../src/Generics.cpp"
#include <iostream>
#include <cmath>
using namespace std;
/*
cd bin/driver
g++ -o kompetisiKartu main.cpp ../src/Card.cpp ../src/GameState.cpp ../src/InventoryHolder.cpp ../src/Player.cpp ../src/Valueable.cpp ../src/Deck.cpp ../src/Table.cpp ../src/Ability.cpp ../src/Generics.cpp ../src/GameManager.cpp; if ($?) {./kompetisiKartu}
*/

int main(){
    bool gameIsOngoing = true;
    int playerCount = 7;
    long int win = 2000000; //set sebagai limit atau set sampai overflow
    Player* players = new Player[playerCount];
    while (findMax(players, playerCount).getPlayerPoint() != win)
    {
        GameState* gameptr = new GameState(players, playerCount);
        GameManager game(gameptr, players);
        //game loop
        if (game.getGameState()->getRound() == 0){
            for (int i = 0; i < playerCount; i++)
            {
                game.getGameState()->dealCards(2);
            }
            for (int i = 0; i < playerCount; i++)
            {
                players[i].showPlayerInfo();
            }
        } else if (game.getGameState()->getRound() == 1){
            game.getGameState()->dealAbility();
            for (int i = 0; i < playerCount; i++)
            {
                players[i].showPlayerInfo();
            }
        } else if (game.getGameState()->getRound() == 5){
            findMax(game.getPlayers(), playerCount).setPlayerPoint(game.getGameState()->getPrize());
        }
        game.getGameState()->playRound();
        game.getGameState()->nextRound();
        delete game.getGameState();
    }
    cin.ignore();
    return 0;
}