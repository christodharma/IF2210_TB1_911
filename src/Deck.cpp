#include "Deck.hpp"

Deck::Deck()
{
    this->_deck = new Inventory;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j < 14; j++)
        {
            if (i==0){
                this->_deck->getInventory().push_back(Card ('h', j));
            } else if (i==1){
                this->_deck->getInventory().push_back(Card ('b', j));
            } else if (i==2){
                this->_deck->getInventory().push_back(Card ('k', j));
            } else if (i==3){
                this->_deck->getInventory().push_back(Card ('m', j));
            }
        }
    }
    ShuffleDeck();
}

Deck::~Deck(){}

void Deck::InitializeDeck(){
    //initilize deck of cards with H, B, K, M char combined with 1-13 int
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j < 14; j++)
        {
            if (i==0){
                this->_deck->getInventory().push_back(Card ('h', j));
            } else if (i==1){
                this->_deck->getInventory().push_back(Card ('b', j));
            } else if (i==2){
                this->_deck->getInventory().push_back(Card ('k', j));
            } else if (i==3){
                this->_deck->getInventory().push_back(Card ('m', j));
            }
        }
    }
}

void Deck::ShuffleDeck()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(this->_deck->getInventory().begin(), this->_deck->getInventory().end(), std::default_random_engine(seed));
}

void Deck::DrawTo(vector<Card>& target)
{
    if (this->_deck->isEmpty()){
        // throw emptyException
    } else {
        Card result(this->_deck->getInventory().back());
        cout << "card drawn: " << result << endl;
        target.push_back(result);
        this->_deck->getInventory().pop_back();
    }
}