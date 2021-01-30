#pragma once
#include "stock.hpp"
#include "player.hpp"

class Share {
public:
    Share();
    Share(Stock*, Player*, double);
    Share(Stock*, Player*, double, int);
    void GetSymbol();
    Stock SetSymbol(const Stock&);
private:
    Stock* stockSymbol;           // Required
    Player* shareHolder;    // Required
    double purchasePrice;   // Required
    int positions = 0;
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
