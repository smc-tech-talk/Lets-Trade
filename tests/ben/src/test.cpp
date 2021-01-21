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
    Transaction* t = new Transaction(STOCK_BUY, 200);
    cout << *t << endl;
    delete t;
    delete d;
    d=NULL;
    t=NULL;

    return 0;
}
