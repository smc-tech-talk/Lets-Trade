#include "portfolio.hpp"

/* Share */
Share::Share(){};
Share::Share(Stock* s, int a)
    :stock(s),
    position(a){};
void Share::IncreaseAmount(int a)
    { this->position += a; };
void Share::DecreaseAmount(int a)
    { this->position -= a; };
// Getter
Stock Share::GetStock()
    { return *(this->stock); };
int Share::GetPosition()
    { return this->position; };

/* Portfolio */
Portfolio::Portfolio(){};
void Portfolio::BuyShare(Stock* stock, int a){
    // if the player has the stock already,
        // share.IncreaseAmount(a);
    Share s = Share(stock, a);
    this->shares.push_back(s);
    // else
};
void Portfolio::SellShare(Stock*, int){ // In progress
    // if the player has the stock already,
        // share.DecreaseAmount(a);
};
// Getter
std::vector<Share> Portfolio::GetShares()
    { return this->shares; };
Share Portfolio::GetShareByIndex(int index)
{
    Share s;
    try {
        s = ( this->shares ).at(index);
        throw "Out of index error";
    } catch(const char* errMessage){
        cout << "Portfolio::Error::" << errMessage << endl;
    }
    return s;
};
