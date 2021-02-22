#pragma once

#include "stock.hpp"
#include "player.hpp"

class Share {
public:
    Share();
    Share(Stock*, Player*, double);
    Stock GetSymbol();
    void SetSymbol(Stock&);
    double GetTotalSpent();
    void toShare();
    int GetPositions();
    void SetPositions(int);
private:
    Stock* stockSymbol;           // Required
    Player* shareHolder;    // Required
    double purchasePrice;   // Required
    int positions = 0; // Any better name?
};

class Certificate {
public:
    Certificate();
    void PrintCertificate();
private:
    Company* company;
    Player* owner;
    Stock* stock;
    Date* date;
};
