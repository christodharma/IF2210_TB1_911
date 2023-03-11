#include "../../src/Combination.hpp"
#include <iostream>
using namespace std;

int main (){
    vector<Card> table;
    vector<Card> inventory;
    table.push_back(Card(1,'H'));
    table.push_back(Card(2,'H'));
    table.push_back(Card(3,'H'));
    inventory.push_back(Card(4,'H'));
    Combination co(table,inventory);
    return 0;
}