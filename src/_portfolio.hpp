#pragma once

#include <vector>
#include <string>
#include "share.hpp"
#include "transaction.hpp"

class Portfolio{

private:
    vector<Share*> playerShares;

public:
    // default constructor
    Portfolio();
    Portfolio(vector<Share*> shares);
    ~Portfolio();
    //void buyShares(Share*, int); // overloading
    //void buyShares(Share*, int, Date*); // overloading
    //void sellShares(Share*, int);
    //int checkPosInt(int n);
    //bool isDuplicate(Share*);
    //int findShareIndex(Share*, Stock*);

    /*display*/
    //void displayPortfolio() const;
    //void displayPlayerInfo() const;
};
