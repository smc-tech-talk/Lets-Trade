// Followed the charyt in https://www.interactivebrokers.com/en/software/am3/am/funding/viewingtransactionhistory.htm
// Date | Status | Type | Amount/Postion | Status
#include "transaction.hpp"

time_t NOW = time(0); // current system date/time
tm* GMT_TIME = gmtime(&NOW);

/* Date */

// Constructors
Date::Date(){ // This will give exact current time
    this->year = (1900 + (GMT_TIME->tm_year));
    this->month = (GMT_TIME->tm_mon);
    this->day = (GMT_TIME->tm_mday);
    this->hour = (GMT_TIME->tm_hour);
    this->time_stamp = ctime(&NOW);
};
Date::Date(int year, int month, int day, int hour, string time_stamp) // This will be used to implement game's time system
    :year(year),
    month(month),
    day(day),
    hour(hour)
        { this->time_stamp = ctime(&NOW); };

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
        Date date = Date();
        this->date = date;
    };
Transaction::Transaction(TRANSACTION_TYPE t, double a) // add hour later
    :type(t),
    amount(a)
    {
        Date date = Date();
        this->date = date;
    };
Transaction::Transaction(TRANSACTION_TYPE t, double a, Date d) // Create Transaction with given Date
    :type(t),
    amount(a),
    date(d){};

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
            return "TRANSACTIONTYPE::Error: Wrong input transaction type";
            break;
    }
};

// __str__
ostream& operator<<(ostream& strm, Date& d) {
    return strm << "\n\nYear:\t\t\t" << d.GetYear() << "\n\nMonth:\t\t\t" << d.GetMonth() << "\n\nDay:\t\t\t" << d.GetDay() << "\n\nHour:\t\t\t" << d.GetHour() << "\n\n";
};
ostream& operator<<(ostream& strm, Transaction& t) {
    Date d = t.date;
    try{
        if(!t.type)
            throw "\n\nTransaction::Error:No specified transaction type\n\n";
        else if(!t.amount)
            throw "\n\nTransaction::Error:Zero amount of the transaction\n\n";
        else
            return strm << "\n\nTransaction Type:\t" << t.GetTransactionType() << "\n\nAmount:\t\t\t$" << t.amount << d;
    }catch(const char* err){
        return strm << err;
    }
};
