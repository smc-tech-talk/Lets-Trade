#ifdef PORTFOLIO_H
#def PORTFOLIO_H

#include <vector>
#include <string>
#include "player.hpp"
#include "banking.hpp"
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
        void buyShares(string tradeSymbol, int tradeShares);
        void sellShares(string tradeSymbol, int tradeShares);
        void tradeStocks(Stock& sS, int tC, int tS);
        /*valudation*/
        bool isNewStock(Stock& s);
        int isPosInt(int n);
        /*display*/
        void displayPortfolio();
        void displayPlayerInfo();
};
#endif
