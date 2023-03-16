#include "InventoryHolder.hpp"

vector<Card> InventoryHolder::emptyInventory = vector<Card>();
InventoryHolder::InventoryHolder(){};
InventoryHolder::~InventoryHolder(){};
bool InventoryHolder::isEmpty(){
    throw new InventoryHolderException();
};
void InventoryHolder::showInventory() const{
    throw new InventoryHolderException();
};
vector<Card>& InventoryHolder::getInventory(){
    throw new InventoryHolderException();
};
vector<Card>& InventoryHolder::operator+=(Card&){
    throw new InventoryHolderException();
};
vector<Card>& InventoryHolder::operator-=(Card&){
    throw new InventoryHolderException();
};
vector<Card>& InventoryHolder::operator+(Card&){
    throw new InventoryHolderException();
};
vector<Card>& InventoryHolder::operator-(Card&){
    throw new InventoryHolderException();
};
vector<Card>& InventoryHolder::operator=(const vector<Card>&){
    throw new InventoryHolderException();
};