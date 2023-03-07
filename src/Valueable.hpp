#ifndef __VALUEABLE_HPP__
#define __VALUEABLE_HPP__

#include <vector>
#include <map>

using namespace std;


//Kelas abstrak yang diinherit oleh Card sebagai singular
//dan Combination sebagai bentuk Card plural
class Valueable{
public:
    Valueable(){};
    virtual ~Valueable(){}; //?? this stucked the prog
    static map<char,double> valueMap;
    virtual double getValue() = 0;
};

class Value : public Valueable {
protected:
    double value;
public:
    // Value(Combination* co);
    Value(double);
    ~Value(){};
    double getValue();
};

//belum
// class Combination : Valueable{
// private:
//     vector<Valueable*> combo;
// public:
//     Combination();
//     ~Combination();
// };

#endif