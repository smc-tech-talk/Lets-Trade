#pragma once
#include <vector>
#include <string>
#include "player.hpp"
#include "banking.hpp"
#include "transaction.hpp"
#include "share.hpp"
#include "stock.hpp"
using namespace std;

class Portfolio{
    private:
        Human* firstName;
        Account* bankAccount;
        vector<Portfolio*> userPortfolio;
        
    public:
        // default constructor
        Portfolio();
        ~Portfolio();
        void buyShares(Share*);
        void sellShares(Share*);
        int checkPosInt(int n);
        bool isDuplicate(Share*);
        
        /*display*/
        void displayPortfolio();
        void displayPlayerInfo();
};
