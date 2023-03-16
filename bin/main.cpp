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
#include "../src/Combination.hpp"
#include "../src/Generics.hpp"
#include "../src/Flush.hpp"
#include "../src/FullHouse.hpp"
#include "../src/HighCard.hpp"
#include "../src/Pair.hpp"
#include "../src/ThreeOfAKind.hpp"
#include "../src/FourOfAKind.hpp"
#include "../src/TwoPair.hpp"
#include "../src/Straight.hpp"
#include "../src/StraightFlush.hpp"

#include <iostream>
#include <cmath>
using namespace std;
/*
cd bin/driver
g++ -o kompetisiKartu main.cpp ../src/*.cpp ; if ($?) {./kompetisiKartu}
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
            }else if (game.getRound() == 5){
                Combination* combs = new Combination[playerCount];
                for (int i=0; i<playerCount; i++) {
                    InventoryHolder *hand = new Player();
                    for (int j=0; j<2; j++) {
                        *hand += players[i].getInventory()[j];
                    }
                    combs[i] = Combination(*hand, game.getTable());
                }

                double* points = new double[playerCount];
                for (int i=0; i<playerCount; i++) {
                    cout << players[i].getPlayerName() << " : " << combs[i].getValue() << " " << combs[i].getType() << endl;
                    points[i] = combs[i].getValue();
                }
                double winnersPoint = findMax(points, playerCount);
                int winnerIndex;
                for (int i=0; i<playerCount; i++) {
                    if (points[i] == winnersPoint) {
                        winnerIndex = i;
                    }
                }
                game.gameEnd(players[winnerIndex]);
            }
            for (int i = 0; i < playerCount; i++)
            {
                players[i].showPlayerInfo();
            }
        // try the switch
        // AbilityInterface a(game.getPlayer(currentTurn).getPlayerAbility(), game, game.getPlayer(currentTurn));

        game.playRound();
        game.nextRound();

        }
    }
    return 0;
}