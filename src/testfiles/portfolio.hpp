#pragma once
#include <memory>
#include "share.cpp"

class Portfolio {
public:
    // Constructors
    Portfolio();
    Portfolio(vector<std::unique_ptr<Stock>>&);

    // Getter
    std::vector<Share> GetShares();
    Share GetShareByIndex(int);
    Share GetShareByStock(Stock*);

    // Methods
    void InitializeEmptyShares(vector<std::unique_ptr<Stock>>&);
    void BuyShare(Stock*, int);
    void SellShare(Stock*, int);
private:
    std::vector<Share> shares;
};
