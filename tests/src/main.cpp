/* Every header files working in progress here */
#include "../include/public_header.hpp"
#include "stock.cpp"
#include "csvExtractor.cpp"
#include "banking.cpp"
#include "transaction.cpp"
//#include "player.cpp"

int main(){

    /* Initializing Data */
    srand(time(NULL));
    Stock* s = new Stock();
    TRANSACTION_TYPE tt;
    tt = BUY_STOCK;

    Transaction* t = new Transaction(tt, 1249.00);
    Date d = t->GetDate();
    cout << "Transaction Amount:\t$"<< t->GetAmount() << endl;
    cout << "Year:\t" << d.year << endl;
    cout << "Month:\t" << d.month << endl;
    cout << "Day:\t" << d.day << endl;
    cout << "Real Time:\t" << d.real_time << endl;
    delete s;
    delete t;
    s=NULL;
    t=NULL;
    return 0;
}

/* Initializers */
/*
vector<Company*> GenerateCompanies(){
    vector<Company*> result;
    return result;
}
vector<Stock*> GenerateStocks(){
    vector<Stock*> result;
    return result;
}
*/
