#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <time.h>

enum TRANSACTION_TYPE { DEFAULT, STOCK_BUY, STOCK_SELL, ACCOUNT_DEPOSIT, ACCOUNT_WITHDRAW };
enum DAYS_OF_MONTH { JAN = 31, FEB = 28, MAR = 31, APR = 30, MAY = 31, JUN = 30,
            JUL = 31, AUG = 31, SEP = 30, OCT = 31, NOV = 30, DEC = 31 };

// enum MONTH { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
class Date {
public:
    // Date(int, int, int, int, string);
    Date();
    Date(int, int, int, int, string);

    // Get
    int GetYear();
    int GetMonth();
    int GetDay();
    int GetHour();
    string GetTimeStamp();

    // Set
    //void SetYear(int);
    //void SetMonth(int);
    //void SetDay(int);
    //void SetHour(int);
    friend ostream& operator<<(ostream& strm, Date& d);

private:
    int year;
    int month;
    int day;
    int hour;
    string time_stamp;
    // double time;
};

class Transaction {
public:
    // Constructors
    Transaction(TRANSACTION_TYPE type);
    Transaction(TRANSACTION_TYPE type, double amount);
    Transaction(TRANSACTION_TYPE type, double amount, Date date);

    // Get
    Date GetDate();
    double GetAmount();
    string GetTransactionType();

    // Set
    void SetDate(Date);

    // In progress
    string GetMonth();

    friend ostream& operator<<(ostream& strm, Transaction& t);

private:
    Date date;
    TRANSACTION_TYPE type;
    double amount;
};

#endif
