#ifndef __ABILITYINTERFACE_HPP__
#define __ABILITYINTERFACE_HPP__

#include "Ability.hpp"
#include "GameState.hpp"
#include <string>
#include <iostream>
using namespace std;

class AbilityInterface {
    private:
        Ability* ability;
        GameState* gameState;
    public:
        AbilityInterface();
        AbilityInterface(Ability*, GameState&, Player&);
        ~AbilityInterface();
        void setInterface(Ability*, GameState&, Player&);
};


#endif