#include "InventoryHolder.hpp"


InventoryHolder::InventoryHolder(){
    vector<Card> x;
    this->inventory = x;
};
InventoryHolder::~InventoryHolder(){
}
vector<Card>& InventoryHolder::operator+=(Card& input){
    this->inventory.push_back(input);
    return this->inventory;
}
vector<Card>& InventoryHolder::operator-=(Card& input){
    for (int i = 0; i < this->inventory.size(); i++)
    {
        if (this->inventory[i] == input){
            this->inventory.erase(this->inventory.begin() + i);
            break;
        } else if (i == this->inventory.size()-1){
            //throw notFoundException;
            cout << "T not found" << endl;
        }
    }
    return this->inventory;
}
bool InventoryHolder::isEmpty(){
    return this->inventory.empty();
}
vector<Card>& InventoryHolder::operator+ (Card& b){
    return *this += b;
}
vector<Card>& InventoryHolder::operator- (Card& b){
    return *this -= b;
}
vector<Card>& InventoryHolder::getInventory(){
    return this->inventory;
}
void InventoryHolder::showInventory() const{
    for (int i = 0; i < this->inventory.size(); i++)
    {
        cout <<"[" << i+1 << "] " << this->inventory[i] << endl;
    }
}
// template<>
// InventoryHolder<Card>::InventoryHolder(){
//     vector<Card> x;
//     this->inventory = x;
// };
// template<>
// InventoryHolder<Card>::~InventoryHolder(){
// }
// template<>
// vector<Card>& InventoryHolder<Card>::operator+=(Card& input){
//     this->inventory.push_back(input);
//     return this->inventory;
// }template<>
// vector<Card>& InventoryHolder<Card>::operator-=(Card& input){
//     for (int i = 0; i < this->inventory.size(); i++)
//     {
//         if (this->inventory[i] == input){
//             this->inventory.erase(this->inventory.begin() + i);
//             break;
//         } else if (i == this->inventory.size()-1){
//             //throw notFoundException;
//             cout << "T not found" << endl;
//         }
//     }
//     return this->inventory;
// }

// template<>
// bool InventoryHolder<Card>::isEmpty(){
//     return this->inventory.empty();
// }

// template<>
// void InventoryHolder<Card>::showInventory() const{
//     for (int i = 0; i < this->inventory.size(); i++)
//     {
//         cout << i+1 << "." << this->inventory[i] << endl;
//     }
// }
// template<>
// vector<Card>& InventoryHolder<Card>::operator+ (Card& b){
//     return *this += b;
// }template<>
// vector<Card>& InventoryHolder<Card>::operator- (Card& b){
//     return *this -= b;
// }
// template<>
// vector<Card>& InventoryHolder<Card>::getInventory(){
//     return this->inventory;
// }