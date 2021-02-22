#include "portfolio.hpp"

/* Portfolio */
Portfolio::Portfolio(){};

Portfolio::Portfolio(vector<std::unique_ptr<Stock>> &stocks){
    InitializeEmptyShares(stocks);
};
void Portfolio::BuyShare(Stock* stock, int a){
    Share s = GetShareByStock(stock);
    s.IncreaseAmount(a);
};
void Portfolio::SellShare(Stock* stock, int a){ // In progress
    Share s = GetShareByStock(stock);
    s.DecreaseAmount(a);
};

// Methods
void Portfolio::InitializeEmptyShares(vector<std::unique_ptr<Stock>> &stocks){
    try{
        for(auto& s : stocks){
            Share share = Share(s.get(), 0);
            this->shares.push_back(share);
        }
    } catch(const char* errMessage){
        exit(1);
    }
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
Share Portfolio::GetShareByStock(Stock* stock)
{
    Share share;
    try {
        for(auto& s : this->shares){
            // Decide which to use. vector.find() or just loop
            if( stock == s.GetStockPtr() )
                share = s;
        }
    } catch(const char* errMessage){
        cout << "Portfolio::Error::" << errMessage << endl;
    }
    return share;
};
