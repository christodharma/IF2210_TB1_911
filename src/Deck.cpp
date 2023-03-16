#include "Deck.hpp"

Deck::Deck()
{
    vector<Card> x;
    this->_deck = x;
    InitializeDeck();
    ShuffleDeck();
}

Deck::~Deck(){ 
}

void Deck::InitializeDeck(){
    for (int rank = 1; rank <= 13; ++rank) {
        for (char suit : {'H', 'B', 'K', 'M'}) {
            this->_deck.emplace_back(suit, rank);
        }
    }
}

void Deck::ShuffleDeck()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(this->_deck.begin(), this->_deck.end(), std::default_random_engine(seed));
}

void Deck::DrawTo(vector<Card>& target)
{
    if (this->_deck.empty()){
        // throw emptyException
    } else {
        target.push_back(this->_deck.back());
        this->_deck.pop_back();
    }
}

void Deck::showInventory() const
{
    for (int i = 0; i < this->_deck.size(); i++)
    {
        cout << this->_deck[i].getAngka() << this->_deck[i].getWarna() << " ";
    }
    cout << endl;
}
vector<Card>& Deck::getDeck()
{
    return this->_deck;
}