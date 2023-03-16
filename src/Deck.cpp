#include "Deck.hpp"

Deck::Deck()
{
    this->_deck = new Inventory;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            if (i == 0)
            {
                Card card(j+1, 'H');
                this->_deck->getInventory().push_back(card);
            }
            else if (i == 1)
            {
                Card card(j+1, 'B');
                this->_deck->getInventory().push_back(card);
            }
            else if (i == 2)
            {
                Card card(j+1, 'K');
                this->_deck->getInventory().push_back(card);
            }
            else if (i == 3)
            {
                Card card(j+1, 'M');
                this->_deck->getInventory().push_back(card);
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
        cout << "before draw:" << Deck::getInventory().back() << endl;
        Card result(Deck::getInventory().back());
        cout << "card drawn: " << result << endl;
        target.push_back(result);
        Deck::getInventory().pop_back();
        cout << "after draw:" << Deck::getInventory().back() << endl;
    }
}

bool Deck::isEmpty()
{
    return this->_deck->isEmpty();
}
void Deck::showInventory() const
{
    for (int i = 0; i < this->_deck->getInventory().size(); i++)
    {
        cout << this->_deck->getInventory()[i].getAngka() << this->_deck->getInventory()[i].getWarna() << " ";
    }
    cout << endl;
}
vector<Card>& Deck::getInventory()
{
    return this->_deck->getInventory();
}
// vector<Card>& Deck::operator+=(Card& card)
// {
//     return this->_deck->getInventory() += (card);
// }
// vector<Card>& Deck::operator-=(Card& card)
// {
//     return this->_deck->getInventory() -=(card);
// }
// vector<Card>& Deck::operator+(Card& card)
// {
//     return this->_deck->getInventory() +(card);
// }
// vector<Card>& Deck::operator-(Card& card)
// {
//     return this->_deck->getInventory() -(card);
// }
vector<Card>& Deck::operator=(const vector<Card>& input)
{
    return this->_deck->getInventory().operator=(input);
}