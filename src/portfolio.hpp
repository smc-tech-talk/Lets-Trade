#pragma once
#include "share.hpp"
#include <vector>
#include <string>
#include "player.hpp"
#include "banking.hpp"
#include "transaction.hpp"
#include "stock.hpp"
using namespace std;

class Portfolio{
    protected:
    
    // friend class Share;
        
        
    public:
        // default constructor
        Portfolio();
        ~Portfolio();
        void buyShares(Stock*, const int);
        void sellShares(Stock*, const int);
        int indexFinder(Stock*);
        // private
        vector<Share*> sharesList;
        
        /*display*/
        void displayPortfolio() const;
        void displayPlayerInfo() const;
};
