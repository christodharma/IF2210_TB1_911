#ifndef __FLUSH_HPP__
#define __FLUSH_HPP__

#include "Valueable.hpp"

class Flush : public Value {
    public:
        Flush(InventoryHolder hold, map<string, InventoryHolder> mapcard);
        ~Flush();
};

#endif