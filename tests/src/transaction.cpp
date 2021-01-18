// Followed the charyt in https://www.interactivebrokers.com/en/software/am3/am/funding/viewingtransactionhistory.htm
// Date | Status | Type | Amount/Postion | Status

#include "transaction.hpp"

time_t NOW = time(0); // current system date/time
tm* GMT_TIME = gmtime(&NOW);

/* Date */
Date::Date(){}; // Default Constructor
Date::Date(int year, int month, int day, int hour, string real_time)
    :year(year),
    month(month),
    day(day),
    hour(hour),
    real_time(real_time){};

/* Transaction */
// Test
Transaction::Transaction() {
    Date date;
    date = Date(
            (1900 + (GMT_TIME->tm_year)),
            (GMT_TIME->tm_mon),
            (GMT_TIME->tm_mday),
            (GMT_TIME->tm_hour),
            ctime(&NOW)
        );
    this->date = date;
};

Date Transaction::GetDate()
    { return this->date; };
