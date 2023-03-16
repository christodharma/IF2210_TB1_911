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

Deck::Deck(string path)
{
    ifstream file;
    while (true) {
        try {
            if (path.substr(path.find_last_of(".") + 1) != "txt") {
                throw new FalseFileType();
            }
            else if (!std::filesystem::exists(path)) {
                throw new UndetectedFile();
            }
            else if (std::filesystem::file_size(path) == 0) {
                throw new EmptyFile();
            }
            else if (std::filesystem::file_size(path) < 189) {
                throw new NotEnoughCard();
            } else {
                break;
            }
        } catch (Exception* e) {
            e->what();
            cout << "Masukkan path file yang benar: ";
            cin >> path;
        }
    }
    file.open(path);

    char warna[52] = {0};
    int angka[52] = {0};

    for( int i=0; i<52; i++)
        file >> warna[i] >> angka[i];

    for( int i=0; i<52; i++)
        this->inventory.push_back(Card(warna[i], angka[i]));

    file.close();
}

Deck::~Deck(){}

void Deck::ShuffleDeck()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(this->inventory.begin(), this->inventory.end(), std::default_random_engine(seed));
}

void Deck::DrawTo(vector<Card>& target)
{
    if (this->inventory.empty()){
        // throw emptyException
    } else {
        Card result(this->inventory.back().getAngka(), this->inventory.back().getWarna());
        // cout << "card drawn: " << result << endl;
        target.push_back(result);
        this->inventory.pop_back();
    }
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