#include "InventoryHolder.hpp"

vector<Card> InventoryHolder::emptyInventory = vector<Card>();
InventoryHolder::InventoryHolder(){};
InventoryHolder::~InventoryHolder(){};
bool InventoryHolder::isEmpty(){
    cout << "InventoryHolder::isEmpty() called" << endl;
    return true;
};
void InventoryHolder::showInventory() const{
    cout << "InventoryHolder::showInventory() called" << endl;
};
vector<Card>& InventoryHolder::getInventory(){
    cout << "InventoryHolder::getInventory() called" << endl;
    return emptyInventory;
};
vector<Card>& InventoryHolder::operator+=(Card&){
    cout << "InventoryHolder::operator+=(Card&) called" << endl;
    return emptyInventory;
};
vector<Card>& InventoryHolder::operator-=(Card&){
    cout << "InventoryHolder::operator-=(Card&) called" << endl;
    return emptyInventory;
};
vector<Card>& InventoryHolder::operator+(Card&){
    cout << "InventoryHolder::operator+(Card&) called" << endl;
    return emptyInventory;
};
vector<Card>& InventoryHolder::operator-(Card&){
    cout << "InventoryHolder::operator-(Card&) called" << endl;
    return emptyInventory;
};
vector<Card>& InventoryHolder::operator=(const vector<Card>&){
    cout << "InventoryHolder::operator=(const vector<Card>&) called" << endl;
    return emptyInventory;
};