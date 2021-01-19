#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <time.h>

enum TRANSACTION_TYPE { STOCK_BUY, STOCK_SELL, ACCOUNT_DEPOSIT, ACCOUNT_WITHDRAW };
enum DAYS_OF_MONTH { JAN = 31, FEB = 28, MAR = 31, APR = 30, MAY = 31, JUN = 30,
            JUL = 31, AUG = 31, SEP = 30, OCT = 31, NOV = 30, DEC = 31 };

// enum MONTH { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
class Date {
public:
    // Date(int, int, int, int, string);
    Date();
    Date(int, int, int, int, string);
    int year;
    int month;
    int day;
    int hour;
    string real_time;

    // double time;
};

class Transaction {
public:
    // Date | Status | Type | Amount/Postion | Status

    // Constructor
    Transaction();
    Transaction(int type, double amount);

    // Get
    Date GetDate();
    double GetAmount();
    // string GetTransactionType();
    // string GetMonth();

    // Set
    void SetDate(Date);

private:
    Date date;
    TRANSACTION_TYPE type;
    double amount;
};

#endif
