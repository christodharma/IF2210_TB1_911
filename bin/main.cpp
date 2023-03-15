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
g++ main.cpp ../src/Card.cpp ../src/GameState.cpp ../src/InventoryHolder.cpp ../src/Player.cpp ../src/Valueable.cpp ../src/Deck.cpp ../src/Table.cpp ../src/Ability.cpp ../src/Generics.cpp ../src/GameManager.cpp -o main; if ($?) {.\main}
g++ main.cpp ..\\src\\Card.cpp ..\\src\\GameState.cpp ..\\src\\InventoryHolder.cpp ..\\src\\Player.cpp ..\\src\\Valueable.cpp ..\\src\\Deck.cpp ..\\src\\Table.cpp ..\\src\\Ability.cpp ..\\src\\Generics.cpp ..\\src\\GameManager.cpp -o main; if ($?) {.\main}
*/

int main(){
    bool gameIsOngoing = true;
    int playerCount = 7;
    long int win = 2000000; //set sebagai limit atau set sampai overflow
    Player* players = new Player[playerCount];
    while (findMax(players, playerCount).getPlayerPoint() < win)
    {
        GameState game(players,playerCount);
        while (game.getRound() < 6)
        {
            //game loop
            if (game.getRound() == 0){
                for (int i = 0; i < playerCount; i++)
                {
                    game.dealCards(i,2);
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
                cout << ":::::::::: Round End ::::::::::"<<endl;
                findMax(players, playerCount).setPlayerPoint(findMax(players, playerCount).getPlayerPoint()+game.getPrize());
                cout << "Player " << findMax(players, playerCount).getPlayerName() << " won " << game.getPrize() << " points" << endl;
                for (int i = 0; i < playerCount; i++)
                {
                    players[i].showPlayerInfo();
                }
            }
            game.playRound();
            game.nextRound();
        }
        // GameState* gameptr = new GameState(players, playerCount);
        // GameManager game(gameptr, players);
        // while (game.getGameState()->getRound() < 6)
        // {
        //     //game loop
        //     if (game.getGameState()->getRound() == 0){
        //         for (int i = 0; i < playerCount; i++)
        //         {
        //             game.getGameState()->dealCards(i,2);
        //         }
        //         for (int i = 0; i < playerCount; i++)
        //         {
        //             players[i].showPlayerInfo();
        //         }
        //     } else if (game.getGameState()->getRound() == 1){
        //         game.getGameState()->dealAbility();
        //         for (int i = 0; i < playerCount; i++)
        //         {
        //             players[i].showPlayerInfo();
        //         }
        //     } else if (game.getGameState()->getRound() == 5){
        //         findMax(game.getPlayers(), playerCount).setPlayerPoint(game.getGameState()->getPrize());
        //     }
        //     game.getGameState()->playRound();
        //     game.getGameState()->nextRound();
        // }
        // delete game.getGameState();
        // delete gameptr;
    }
    // cin.ignore();
    return 0;
}