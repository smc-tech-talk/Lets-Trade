#include "stock.hpp"
time_t NOW = time(0); // current system date/time

/* Transaction */
Transaction::Transaction(int t, double c){
    currentTime = ctime(&NOW);   // convert in string form
    type = t;
    cost = c;
};

/* Company */
Company::Company(string n, double p, double v){
    companyName = n;
    companyPrice = p;
    companyValue = v;
};

/* Stock */

// Constructors
Stock::Stock(){
    cout << "Stock Info\n\n" << endl;
};
Stock::Stock(string n, string s, double p){
    stockName = n;
    stockSymbol = s;
    stockCurrentPrice = p;
};

// Get
string Stock::GetName(){ return stockName; };
double Stock::GetPrice(){ return stockCurrentPrice; };

// Set
void Stock::SetName(string n){ stockName = n; };
void Stock::SetPrice(double p){ stockCurrentPrice = p; };
void Stock::SetCompany(Company* c) { ownedCompany =  c; };

// Methods
double PriceChangeRate(){

};
bool UpOrDown(){

};

// Tests
void Stock::PrintCompany(){
    cout << ownedCompany->companyName << endl;
};

// Destructor
Stock::~Stock(){
    delete ownedCompany;
    ownedCompany = NULL;
};

// String Representation of the object
ostream& operator<<(ostream& strm, const Stock& s) {
    return strm << "String Representation of Stock Object: \n\n";
};
