#ifndef STOCK_H
#define STOCK_H

#include <time.h>
#include <ctime>
#include <vector>

enum TRANSACTION_TYPE { SELL, BUY };

struct Transaction{
    Transaction(int, double);
    string currentTime;
    int type;
    double cost;

    // ToString
    friend ostream& operator<<(ostream& strm, const Transaction& t);
};

struct Company{
    Company(string);
    Company(string, string);
    string companyName;
    string companyType;
    double companyPrice;
    double companyValue;

    // ToString
    friend ostream& operator<<(ostream& strm, const Company& c);
};

class Stock{
public:
    Stock(string);
    Stock(string, double, Company*);

    // Get
    double GetCurrentPrice();
    double GetPrevPrice();
    double GetChangedPercentage();
    string GetSymbol();
    Company GetStockIssuer();
    vector<Transaction> GetTransactionHistory();

    // Set
    void SetCurrentPrice(double);
    void SetPrevPrice(double);
    void SetSymbol(string);
    void SetStockIssuer(Company*); // Just passing pointer

    // Methods
    void AddTransactionHistory(int, double);
    void UpdateChangedPercentage();
    void UpdateStockPrice();
    int GetRandomNumber(int);
    double GetRandomStockPrice(int = 4);

    // In Progress


    // Tests
    void PrintTransactionHistory();

    // Dectructor
    ~Stock();

protected:
    double stockCurrentPrice;
    double stockPrevPrice;
    double stockUniqueConstant = 0.01418953;
    double stockChangedPercentage;
    string stockSymbol;
    Company* stockIssuer; // Stock Issuer
    vector<Transaction> transactionHistory; // Neead fix

    // ToString
    friend ostream& operator<<(ostream& strm, const Stock& s);
};

#endif
