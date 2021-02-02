#ifndef SHARE_H
#define SHARE_H
#include "stock.hpp"
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
    int numberOfShares = 0; // Any better name?
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

#endif
