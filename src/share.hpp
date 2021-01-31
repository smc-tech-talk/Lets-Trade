#pragma once
#include "player.hpp"
#include "stock.hpp"


class Share {
public:
    Share();
    Share(Stock*, Player*, double);
    Stock GetSymbol();
    void SetSymbol(Stock&);
    double GetTotalSpent();
    void toShare();
    int GetPosition();
private:
    Stock* stockSymbol;           // Required
    Player* shareHolder;    // Required
    double purchasePrice;   // Required
    int position;
    double totalSpent;
    friend class Portfolio;
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
