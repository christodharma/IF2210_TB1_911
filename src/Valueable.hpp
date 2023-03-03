#ifndef __CARDMECHANIC_HPP__
#define __CARDMECHANIC_HPP__

#include <vector>
#include <map>
using namespace std;


//Kelas abstrak yang diinherit oleh Card sebagai singular
//dan Combination sebagai bentuk Card plural
class Valueable{
protected:
    float value;
public:
    Valueable();
    virtual float getValue();
    map<char,float> valueMap;
};

class Combination : Valueable{
private:
    vector<Valueable*> combo;
public:
    float getValue();
};

#endif