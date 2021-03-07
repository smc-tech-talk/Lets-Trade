#pragma once

#include <memory>
#include "stock.hpp"
#include "transaction.hpp"

#ifndef SHARE_H
#define SHARE_H

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
    std::vector<Transaction> GetTransactionHistory();

    // Setter
    void SetValue(double);

private:
    Stock* stock;
    int position = 0;
    std::vector<Transaction> transactionHistory;
    double value = 0.00;
};

#endif
