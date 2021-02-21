#pragma once
#include <memory>
#include "../stock.hpp"

class Share {
public:
    Share();
    Share(Stock*, int);
    void IncreaseAmount(int);
    void DecreaseAmount(int);

    // Getter
    Stock GetStock();
    int GetPosition();
private:
    Stock* stock;
    int position;
};

class Portfolio {
public:
    // Constructors
    Portfolio();

    // Getter
    std::vector<Share> GetShares();
    Share GetShareByIndex(int);
    // Setter

    // Methods
    void BuyShare(Stock*, int);
    void SellShare(Stock*, int);
private:
    std::vector<Share> shares;
};
