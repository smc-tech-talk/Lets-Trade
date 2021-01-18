// Followed the charyt in https://www.interactivebrokers.com/en/software/am3/am/funding/viewingtransactionhistory.htm
// Date | Status | Type | Amount/Postion | Status
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "transaction.hpp"

time_t NOW = time(0); // current system date/time
tm* GMT_TIME;
/* Date */
Date::Date(int day, int month,int  year, string real_time){
    
};

/* Transaction */
// Test
Transaction::Transaction(){
    GMT_TIME = gmtime(&NOW);
    Date date = Date();
    this->day = (GMT_TIME->tm_mday);
    this->month = (GMT_TIME->tm_mon);
    this->year = 1900 + (GMT_TIME->tm_year);
    this->real_time = ctime(&NOW);
};

Transaction::Transaction(int hour, double amount){

};



#endif
