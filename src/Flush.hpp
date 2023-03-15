#ifndef __FLUSH_HPP__
#define __FLUSH_HPP__

#include "Valueable.hpp"
#include "InventoryHolder.hpp"

class Flush : public Value {
    private:
        InventoryHolder hold; // kombinasi kartu
        map<string, InventoryHolder> mapcard;
    public:
        Flush(InventoryHolder hold, map<string, InventoryHolder> mapcard);
        ~Flush();
};

#endif