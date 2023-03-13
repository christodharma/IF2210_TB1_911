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
    static map<char,string> dictWarna;
    virtual double getValue() const = 0;
};

class Value : public Valueable {
protected:
    double value;
public:
    // Value(Combination* co);
    Value(double);
    ~Value(){};
    double getValue() const;
};

#endif