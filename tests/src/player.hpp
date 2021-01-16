#include <vector>
#include <string>
// #inlcude <pair>;
using namespace std;

class Player{
    private:
        string playerName;
        // Player age ... more infos
        double bankBalance; // => Should be Account bankAccount;
        vector<pair<Stock*, int>> portfolio; // => <Stock pointer, number of stock shares>
    public:
        // default constructor
        Player();
        Player(string pN);
        void setPlayerName(string pN);
        void setBankBalance(double bB);
        string getPlayerName();
        double getBankBalance();
        // void SellStock();
        // void BuyStock();
};


/*
1. Use <pair> to add quantity value to each stock share in portfolio.
2. Prevent assigning less than 1 number of stock share.
    ex) pair<Stock*, int> p = make_pair(stockPtr, 0); => ERROR
3.
*/
