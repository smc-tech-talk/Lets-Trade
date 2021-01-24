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
        vector<Portfolio*> userShares;
    string playerName;
    int playerAge;
        
        
    public:
        // default constructor
        Portfolio();
        ~Portfolio();
        void buyShares(Share*, int, Date*);
        void sellShares(Share*, int, Date*);
        int checkPosInt(int n);
        bool isDuplicate(Share*);
        int findShareIndex(Share*, Stock*);
        
        /*display*/
        void displayPortfolio();
        void displayPlayerInfo();
};
