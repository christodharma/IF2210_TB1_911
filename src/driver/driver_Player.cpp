#include "../InventoryHolder.hpp"
#include "../Player.hpp"
#include "../Card.hpp"
#include "../Valueable.hpp"
#include <iostream>
using namespace std;


//compile
//g++ -o driver driver_Player.cpp ../InventoryHolder.cpp ../Player.cpp ../Card.cpp ../Valueable.cpp
int main(){
    Player p1("Alice");
    cout << "Player name: "<<p1.getPlayerName() << endl;
    cout << "Player point: "<<p1.getPlayerPoint() << endl;
    if (p1.isEmpty()){
        cout << p1.getPlayerName() << " is not holding any card" << endl;
    } else {
        cout << p1.getPlayerName() << " have something" << endl;
    }
    return 0;
}