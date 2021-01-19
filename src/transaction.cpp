// Followed the charyt in https://www.interactivebrokers.com/en/software/am3/am/funding/viewingtransactionhistory.htm
// Date | Status | Type | Amount/Postion | Status
#include "transaction.hpp"

time_t NOW = time(0); // current system date/time
tm* GMT_TIME = gmtime(&NOW);

/* Date */
Date::Date(){}; // Default Constructor
Date::Date(int year, int month, int day, int hour, string time_stamp)
    :year(year),
    month(month),
    day(day),
    hour(hour),
    time_stamp(time_stamp){};
int Date::GetYear()
    { return this->year; };
int Date::GetMonth()
    { return this->month; };
int Date::GetDay()
    { return this->day; };
int Date::GetHour()
    { return this->hour; };
string Date::GetTimeStamp()
    { return this->time_stamp; };


/* Transaction */
// Constructors
Transaction::Transaction(TRANSACTION_TYPE t)
    :type(t)
    {
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

Transaction::Transaction(TRANSACTION_TYPE t, double a) // add hour later
    :type(t),
    amount(a)
    {
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

// Get
Date Transaction::GetDate()
    { return this->date; };
double Transaction::GetAmount()
    { return this->amount; };
string Transaction::GetTransactionType(){
    TRANSACTION_TYPE t;
    t = this->type;
    switch (t) {
        case STOCK_BUY: return "Buy Stock"; break;
        case STOCK_SELL: return "Sell Stock"; break;
        case ACCOUNT_DEPOSIT: return "Bank Account Deposit"; break;
        case ACCOUNT_WITHDRAW: return "Bank Account Withraw"; break;
        default:
            return "TRANSACTIONTYPE::Error: No such transaction type";
            break;
    }
};

ostream& operator<<(ostream& strm, Transaction& t) {
    Date d = t.date;
    try{
        if(!t.type)
            throw "\n\nTransaction::Error:No specified transaction type\n\n";
        else if(!t.amount)
            throw "\n\nTransaction::Error:Zero amount of the transaction\n\n";
        else
            return strm << "\n\nTransaction Type:\t" << t.GetTransactionType() << "\n\nAmount:\t\t$" << t.amount << "\n\nYear:\t\t" << d.GetYear() << "\n\nMonth:\t\t" << d.GetMonth() << "\n\nDay:\t\t" << d.GetDay() << "\n\nHour:\t\t" << d.GetHour() << "\n\n";

    }catch(const char* err){
        return strm << err;
    }

};
