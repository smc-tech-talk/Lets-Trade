#ifndef STOCK_H
#define STOCK_H
#include <time.h>
#include <ctime>
#include <conio.h>
#include <vector>
enum TRANSACTION_TYPE { BUY, SOLD };

struct Transaction{
    Transaction(int, double);
    string currentTime;
    int type;
    double cost;
};

struct Company{
    Company(string, double, double);
    string companyName;
    double companyPrice;
    double companyValue;
};

class Stock{
public:
    Stock();
    Stock(string, double);

    // Get
    string GetName();
    double GetPrice();

    // Set
    void SetName(string);
    void SetPrice(double);
    void SetCompany(Company*); // Just passing pointer

    // Methods

    // Tests
    void PrintCompany();

    /* Unfinished Methods */
    double PriceChangeRate();
    bool UpOrDown();

    // Dectructor
    ~Stock();


protected:
    double stockCurrentPrice;
    double stockPrevPrice;
    string stockName;
    string stockSymbol;
    Company* ownedCompany;
    vector<Transaction> transactionHistory();

    friend ostream& operator<<(ostream& strm, const Stock& s);
};

#endif
