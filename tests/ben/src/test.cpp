/* Every header files working in progress here */
#include "../include/public_header.hpp"
#include "stock.cpp"
#include "csvExtractor.cpp"
#include "banking.cpp"
#include "player.cpp"
#include "transaction.cpp"
//#include "player.cpp"

int main(){
    /* Initializing Data */
    srand(time(NULL));
    Date* d = new Date();
    Transaction t(STOCK_BUY, 200, *d);
    Transaction t2(STOCK_SELL, 45.05, *d);
    Transaction t3(STOCK_BUY, 105.680, *d);

    vector<Transaction> v;
    Transaction::AddTransaction(v, t);
    Transaction::AddTransaction(v, t2);
    Transaction::AddTransaction(v, t3);

    for(auto& t: v){
        cout << t << endl;
    }

    delete d;
    d=NULL;

    return 0;
}
