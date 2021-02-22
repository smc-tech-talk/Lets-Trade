#pragma once
#include <memory>
#include "../stock.hpp"

class Share {
public:
    Share();
    Share(Stock*, int);

    // Methods
    void IncreaseAmount(int);
    void DecreaseAmount(int);

    // Getter
    Stock GetStock();
    Stock* GetStockPtr();
    int GetPosition();
private:
    Stock* stock;
    int position;
};
