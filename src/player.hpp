#include <vector>
#include <string>
#include "banking.hpp"
#include "stock.hpp"
using namespace std;

class Player{
    private:
        string playerName;
        double playerAge;
        Account* bankAccount;
        // get stock pointer and num of shares
        vector< pair <Stock*, int> > portfolio;
        
        
    public:
        // default constructor
        Player();
        Player(string pN);
        ~Player();
        // setter
        void setPlayerName(string pN);
        void setPlayerAge(int pA);
        // getter
        string getPlayerName();
        int getPlayerAge();
        /*-portfolio-*/
        /*trade*/
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
