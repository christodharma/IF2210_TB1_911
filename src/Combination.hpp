#ifndef __COMBINATION_HPP__
#define __COMBINATION_HPP__

#include "Valueable.hpp"
#include "MapCard.hpp"
#include "FourOfAKind.hpp"
#include "FullHouse.hpp"
// ... include semua jenis kombinasi

class Combination {
    protected:
        Valueable typecomb; // tipe kombinasi
        MapCard mapcard; // map yang berisi kartu
    public:
        Combination();
        Combination(MapCard mapcard);
        ~Combination();
        Valueable getTypeComb();
        double getValue();
        string getType() const;
}

#endif