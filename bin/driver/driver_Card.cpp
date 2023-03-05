#include "../../src/Card.hpp"
#include "../../src/Valueable.hpp"
#include <iostream>
using namespace std;

//compile
//g++ -o driver_Card driver_Card.cpp ../../src/Card.cpp ../../src/Valueable.cpp
int main(){
    Card a('B', 6);
    Card b('k', 13);
    cout << b.getWarna() << endl;
    cout << b.getValue() << endl;
    if (a > b){
        a.printCard();
        cout << ">" << endl;
        b.printCard();
    } else if ( a < b) {
        a.printCard();
        cout << "<" << endl;
        b.printCard();
    } else if (a == b){
        a.printCard();
        cout << "==" << endl;
        b.printCard();
    }
    return 0;
}