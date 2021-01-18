#include <time.h>

enum TRANSACTION_TYPE { BUY_STOCK, SELL_STOCK, DEPOSIT, WITHDRAW };
enum DAYS_OF_MONTH { JAN = 31, FEB = 28, MAR = 31, APR = 30, MAY = 31, JUN = 30,
            JUL = 31, AUG = 31, SEP = 30, OCT = 31, NOV = 30, DEC = 31 };
enum MONTH = { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
struct Date {
    Date();

    int year;
    int month;
    int day;
    int hour;

    // double time;
};

class Transaction {
public:
    // Date | Status | Type | Amount/Postion | Status
    // Constructor
    Transaction();
    Transaction(int hour, double amount);

    // Get
    Date GetDate();

    // Set
    void SetDate();

private:
    Date date;
    int type;
    double amount;
    string real_time;
};
