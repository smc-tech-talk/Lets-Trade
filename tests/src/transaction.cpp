// Followed the charyt in https://www.interactivebrokers.com/en/software/am3/am/funding/viewingtransactionhistory.htm
// Date | Status | Type | Amount/Postion | Status
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "transaction.hpp"

time_t NOW = time(0); // current system date/time
tm* GMT_TIME = gmtime(&NOW);
/* Date */
Date::Date(int year, int month, int day, int hour, string real_time){
    this->year = year;
    this->month = month;
    this->day = day;
    this->hour = hour;
    this->real_time = real_time;
};

/* Transaction */
// Test
Transaction::Transaction(){
    Date date = Date(
        (1900 + (GMT_TIME->tm_year)),
        (GMT_TIME->tm_mon),
        (GMT_TIME->tm_mday),
        (GMT_TIME->tm_hour),
        ctime(&NOW)
    );
    this->date = date;
};

Transaction::GetDate(){ return this->Date; };

Transaction::Transaction(int hour, double amount){

};



#endif
