#include "Deck.hpp"

Deck::Deck() : InventoryHolder()
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

Deck::~Deck(){}

void Deck::ShuffleDeck()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(this->inventory.begin(), this->inventory.end(), std::default_random_engine(seed));
}

Card& Deck::Draw()
{
    Card& result = this->inventory.back();
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