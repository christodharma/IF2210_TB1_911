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
    long int win = pow(2,32);
    Player* players = new Player[playerCount];
    while (findMax(players, playerCount).getPlayerPoint() < win)
    {
        GameState game(players,playerCount);
        while (game.getRound() < 6)
        {
            //game loop
            if (game.getRound() == 0){
                cout << "\tIn this round, you will get 2 cards\t" << endl
                    << "\tPress enter to continue\t" << endl;
                cin.ignore();
                cin.get();
                for (int i = 0; i < playerCount; i++)
                {
                    game.dealCards(i,2);
                }
                for (int i = 0; i < playerCount; i++)
                {
                    players[i].showPlayerInfo();
                }
            } else if (game.getRound() == 1){
                cout << "\tIn this round, you will get an ability!\t" << endl
                    << "\tPress enter to continue\t" << endl;
                cin.ignore();
                cin.get();
                game.dealAbility();
                for (int i = 0; i < playerCount; i++)
                {
                    players[i].showPlayerInfo();
                }
            }
            game.playRound();
            game.nextRound();
        }
        game.gameEnd(players[0]); // Pemain menang
        cout << "Game ended" << endl
            << "Press enter to continue" << endl;
        cin.ignore();
        cin.get();
    }
    // F.S. SATU game selesai dan pemain PERTAMA menang
    // set sesuai mekanik game
    return 0;
}