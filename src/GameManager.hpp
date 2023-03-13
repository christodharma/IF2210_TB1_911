#ifndef __GAMEMANAGER_HPP__
#define __GAMEMANAGER_HPP__

#include "GameState.hpp"
#include "InventoryHolder.hpp"
// #include "Valueable.hpp" //maybe

//kelas abstrak yang ngurusin perpindahan objek(kartu) dan eksekusi ability
class GameManager : public GameState, public InventoryHolder{
    public:
        GameManager(){};
        virtual ~GameManager(){};
        virtual void executeAbility()=0;
        virtual void moveCard()=0;
        virtual void showInventory()=0;
        virtual bool isEmpty()=0;
        virtual vector<Card>& getInventory()=0;
        virtual vector<Card>& operator+=(Card&)=0;
        virtual vector<Card>& operator-=(Card&)=0;
        virtual vector<Card>& operator+(Card&)=0;
        virtual vector<Card>& operator-(Card&)=0;
};

#endif