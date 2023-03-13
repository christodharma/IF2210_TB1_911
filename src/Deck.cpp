#include "Deck.hpp"

Deck::Deck() : InventoryHolder()
{}

Deck::~Deck()
{
}

void Deck::InitiateDeck()
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

void Deck::ShuffleDeck()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(this->inventory.begin(), this->inventory.end(), g);
}

Card& Deck::DrawCard()
{
    Card& card = this->inventory.back();
    this->inventory.pop_back();
}