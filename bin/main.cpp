#include "../src/Card.hpp"
#include "../src/GameState.hpp"
#include "../src/InventoryHolder.hpp"
#include "../src/Player.hpp"
#include "../src/Valueable.hpp"
#include "../src/Deck.hpp"
#include "../src/Table.hpp"
#include "../src/Ability.hpp"
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
using namespace std;
/*
cd bin/driver
g++ -o kompetisiKartu main.cpp ../src/*.cpp ; if ($?) {./kompetisiKartu}
g++ -o kompetisiKartu main.cpp ../src/Card.cpp ../src/GameState.cpp ../src/InventoryHolder.cpp ../src/Player.cpp ../src/Valueable.cpp ../src/Deck.cpp ../src/Table.cpp ../src/Ability.cpp ../src/Generics.cpp ../src/Combination.cpp ../src/Flush.cpp ../src/StraightFlush.cpp ../src/FullHouse.cpp ../src/ThreeOfAKind.cpp ../src/ ; if ($?) {./kompetisiKartu}
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
        } else if (game.getRound() == 6){
            gameIsOngoing = false;
        }

        // try the switch
        // AbilityInterface a(game.getPlayer(currentTurn).getPlayerAbility(), game, game.getPlayer(currentTurn));

        game.playRound();
        game.nextRound();

        if (game.getRound() == 6){
            Combination* combs = new Combination[playerCount];
            for (int i=0; i<playerCount; i++) {
                InventoryHolder *hand = new Player();
                for (int j=0; j<2; j++) {
                    *hand += players[i].getInventory()[j];
                }
                combs[i] = Combination(*hand, game.getTable());
            }

            for (int i=0; i<playerCount; i++) {
                cout << players[i].getPlayerName() << " : " << combs[i].getValue() << " " << combs[i].getType() << endl;
            }
        }
    }
    // cin.ignore();
    return 0;
}