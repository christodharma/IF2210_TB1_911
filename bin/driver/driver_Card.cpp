#include "../../src/Card.hpp"
#include "../../src/Valueable.hpp"
#include <iostream>
using namespace std;

//compile
//g++ -o driver_Card driver_Card.cpp ../../src/Card.cpp ../../src/Valueable.cpp
int main(){
    Card a('B', 6);
    Card b('k', 13);
    Card b1('k', 13);
    cout << b.getWarna() << endl;
    cout << b.getValue() << endl;
    if (a > b){
        cout << a << ">" << b << endl;
    } else if ( a < b) {
        cout << a << "<" << b << endl;
    } else if (a == b){
        cout << a << "==" << b << endl;
    }
    if (b1 > b){
        cout << b1 << ">" << b << endl;
    } else if ( b1< b) {
        cout << b1 << "<" << b << endl;
    } else if (b1== b){
        cout << b1 << "==" << b << endl;
    }
    return 0;
}