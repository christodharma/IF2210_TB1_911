#include "Deck.hpp"

template<class T>
Deck<T>::Deck() : InventoryHolder<T>(){}
template<>
Deck<Card>::Deck() : InventoryHolder<Card>()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j < 14; j++)
        {
            if (i==0){
                this->inventory.push_back(Card ('h', j));
            } else if (i==1){
                this->inventory.push_back(Card ('b', j));
            } else if (i==2){
                this->inventory.push_back(Card ('k', j));
            } else if (i==3){
                this->inventory.push_back(Card ('m', j));
            }
        }
    }
}

template<class T>
Deck<T>::~Deck(){}

template<class T>
void Deck<T>::ShuffleDeck()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(this->inventory.begin(), this->inventory.end(), std::default_random_engine(seed));
}

template<class T>
T& Deck<T>::Draw()
{
    T& result = this->inventory.back();
    this->inventory.pop_back();
    return result;
}
// template<>
// Deck<Card>::Deck() : InventoryHolder<Card>(){}
// template<>
// Deck<Card>::~Deck(){}
// template<>
// void Deck<Card>::ShuffleDeck()
// {
//     unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//     std::shuffle(this->inventory.begin(), this->inventory.end(), std::default_random_engine(seed));
// }
// template<>
// Card& Deck<Card>::Draw()
// {
//     Card& result = this->inventory.back();
//     this->inventory.pop_back();
//     return result;
// }