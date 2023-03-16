#ifndef __FLUSH_HPP__
#define __FLUSH_HPP__

#include "Valueable.hpp"
#include "InventoryHolder.hpp"

class Flush : public Value {
    public:
        Flush(map<string, InventoryHolder> mapcard);
        ~Flush();
};

#endif