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
        void buyShares(const Share&, int, const Date&);
        void sellShares(const Share&, int, const Date&);
        int checkPosInt(const int n) const;
        bool isDuplicate(const Share&) const;
        int findShareIndex(const Share&, const Stock&) const;
        
        /*display*/
        void displayPortfolio() const;
        void displayPlayerInfo() const;
};
