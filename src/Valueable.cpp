#include <vector>
#include <map>
#include "Valueable.hpp"
using namespace std;

Valueable::Valueable(){
    valueMap['h'] = 0;
    valueMap['H'] = 0;
    valueMap['b'] = 0.3;
    valueMap['B'] = 0.3;
    valueMap['k'] = 0.6;
    valueMap['K'] = 0.6;
    valueMap['m'] = 0.9;
    valueMap['M'] = 0.9;
}