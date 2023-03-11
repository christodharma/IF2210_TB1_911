// #include "../src/Ability.hpp"
#include "../src/Card.hpp"
#include "../src/GameState.hpp"
#include "../src/InventoryHolder.hpp"
#include "../src/Player.hpp"
#include "../src/Valueable.hpp"
#include <iostream>
#include <string>
using namespace std;
/*
cd bin/driver
g++ -o kompetisiKartu main.cpp ../src/Card.cpp ../src/GameState.cpp ../src/InventoryHolder.cpp ../src/Player.cpp ../src/Valueable.cpp
../src/Ability.cpp
*/

int main(){
    GameState game;
    Player p1("Alice");
    Player p2("Bobby");
    Player p3("Chloe");
    Player p4("Daphne");
    Player p5("Ezra");
    Player p6("Flo");
    Player p7("Gesya");
    game.InitiateDeck();
    while(game.isGameOngoing()){
        game.NextRound();
        cout << "Round " << game.getRound() << " is starting" << endl;
        for (int i = 0; i < 7; i++)
        {
            cout << "Action for player " << i+1 << endl;
            string input;
            cin >> input;
            if (input == "NEXT"){
                cout << "Giliran dilanjut ke pemain selanjutnya." << endl;
            } else if (input == "RE-ROLL"){
                cout << "Melakukan pembuangan kartu yang sedang dimiliki" << endl <<
                "Kamu mendapatkan 2 kartu baru yaitu: " << endl <<
                "1. 2 Merah" << endl <<
                "2. 4 Biru" << endl;
                // game.getCardFromDeck().getCardName() << endl <<
            } else if (input == "DOUBLE"){
                cout << "<nama_pemain> melakukan DOUBLE!" << endl <<
                "Poin hadiah naik dari "<<game.getPrize()<<" menjadi "<<game.getPrize()<<"!" << endl;
            } else if (input == "QUADRUPLE"){
                cout << "<nama_pemain> melakukan QUADRUPLE!" << endl <<
                "Poin hadiah naik dari "<<game.getPrize()<<" menjadi "<<game.getPrize()<<"!" << endl;
                //if (ga punya ability QUADRUPLE)
                cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability QUADRUPLE." << endl;
            } else if (input == "HALF"){
                cout << "<nama_pemain> melakukan HALF!"<<endl<<
                "Poin hadiah turun dari "<<game.getPrize()<<" menjadi "<<game.getPrize()<<"!" << endl;
            } else if (input == "QUARTER"){
                cout << "<nama_pemain> melakukan QUARTER!"<<endl<<
                "Poin hadiah turun dari "<<game.getPrize()<<" menjadi "<<game.getPrize()<<"!" << endl;
                //if (ga punya ability QUADRUPLE)
                cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability QUARTER." << endl;
            } //... dan setereusnya dengan semua ability
            // else {
            //     //throw invalidInputException();
            // }
        }
        cout << "Round " << game.getRound() << " is over" << endl;
    }
    cout << "Program is waiting for you to press enter to continue" << endl;
    cin.ignore();
    return 0;
}