#ifndef STOCK_H
#define STOCK_H

#include <time.h>
#include <conio.h>
#include <ctime>
#include <vector>

enum TRANSACTION_TYPE { SELL, BUY };

struct Transaction{
    Transaction(int, double);
    string currentTime;
    int type;
    double cost;

    friend ostream& operator<<(ostream& strm, const Transaction& t);
};

struct Company{
    Company(string);
    Company(string, string);
    Company(string, string, double, double);
    string companyName;
    string companyType;
    double companyPrice;
    double companyValue;

    friend ostream& operator<<(ostream& strm, const Company& c);
};

class Stock{
public:
    Stock(string);
    Stock(string, double, Company*);

    // Get
    double GetCurrentPrice();
    double GetPrevPrice();
    string GetSymbol();
    Company GetOwnedCompany();
    vector<Transaction> GetTransactionHistory();

    // Set
    void SetCurrentPrice(double);
    void SetPrevPrice(double);
    void SetSymbol(string);
    void SetCompany(Company*); // Just passing pointer

    // Methods
    void AddTransactionHistory(int, double);
    double GetRandomStockPrice(int, int);
    string UpOrDown();

    // Tests
    void PrintCompany();
    void PrintTransactionHistory();

    // Dectructor
    ~Stock();

protected:
    double stockCurrentPrice;
    double stockPrevPrice;
    string stockSymbol;
    Company* ownedCompany;
    vector<Transaction> transactionHistory; // Neead fix

    friend ostream& operator<<(ostream& strm, const Stock& s);
};

#endif
