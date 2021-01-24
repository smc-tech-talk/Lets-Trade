#ifndef SHARE_H
#define SHARE_H
#include "stock.hpp"
#include "player.hpp"

class Share {
public:
    Share(double);
private:
    Stock* stock;
    Player* shareHolder;
    int numberOfShares = 0; // Any better name?
    double purchasePrice;
};

#endif
