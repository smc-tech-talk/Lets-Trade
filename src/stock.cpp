#include "stock.hpp"
time_t NOW = time(0); // current system date/time

/* Transaction */
Transaction::Transaction(int t, double c){
    currentTime = ctime(&NOW);   // convert in string form
    type = t;
    cost = c;
};

/* Company */
Company::Company(string n)
    :companyName(n){};
<<<<<<< HEAD
Company::Company(string n, string t)
    :companyName(n),
    companyType(t),
    companyPrice(0.00),
    companyValue(0.00){};
=======

Company::Company(string n, string t, double p, double v)
    :companyName(n),
    companyType(t),
    companyPrice(p),
    companyValue(v){};
>>>>>>> f74235d33762878935d0ffcaa5e2b521b94a0332

/* Stock */
Stock::Stock(string s)
    :stockSymbol(s){};

Stock::Stock(string s, double p, Company* c)
    :stockSymbol(s),
    stockCurrentPrice(p),
    ownedCompany(c){};

// Get
<<<<<<< HEAD
double Stock::GetCurrentPrice(){ return stockCurrentPrice; };
double Stock::GetPrevPrice(){ return stockPrevPrice; };
string Stock::GetSymbol(){ return stockSymbol; };
=======
double Stock::GetPrice(){ return stockCurrentPrice; };
>>>>>>> f74235d33762878935d0ffcaa5e2b521b94a0332
vector<Transaction> Stock::GetTransactionHistory(){ return transactionHistory; };
Company Stock::GetOwnedCompany(){ return *ownedCompany; };

// Set
<<<<<<< HEAD
void Stock::SetCurrentPrice(double cp){ stockCurrentPrice = cp; };
void Stock::SetPrevPrice(double pp){ stockPrevPrice = pp; };
void Stock::SetSymbol(string s){ stockSymbol = s; };
=======
void Stock::SetPrice(double p){ stockCurrentPrice = p; };
>>>>>>> f74235d33762878935d0ffcaa5e2b521b94a0332
void Stock::SetCompany(Company* c){ ownedCompany =  c; };

// Methods
string Stock::UpOrDown(){
    string symbol;
    if(!stockPrevPrice)
        return "No previous price of the stock";
    else if(stockPrevPrice == stockCurrentPrice)
        symbol = "=";
<<<<<<< HEAD
    else{
        bool margin = ((stockCurrentPrice - stockPrevPrice) > 0);
        if(margin) symbol = "+";
        else symbol = "-";
=======
    }else{
        bool margin = ((stockCurrentPrice - stockPrevPrice) > 0);
        if(margin)
            return "+";
        else
            return "-";
>>>>>>> f74235d33762878935d0ffcaa5e2b521b94a0332
    }
    return symbol;
};

/*template <class T>
void Stock::AddTransactionHistory(T t, <transactionHistory> --> Edit later!!){
    T t;
    <>.push_back(t);
};*/

void Stock::AddTransactionHistory(int type,  double cost){
    Transaction t(type, cost);
    transactionHistory.push_back(t);
};
double Stock::GetRandomStockPrice(int start, int end){

};


// Tests
void Stock::PrintCompany(){
    cout << ownedCompany->companyName << endl;
};
void Stock::PrintTransactionHistory(){
    for(auto& t : transactionHistory)
        cout << t;
};

// Destructor
Stock::~Stock(){
    delete ownedCompany;
    ownedCompany = NULL;
};

// String Representation of the object
ostream& operator<<(ostream& strm, const Stock& s) {
    return strm << "\n\n" << "Stock Symbol: " << s.stockSymbol << "\n\nCurrent Price: " << s.stockCurrentPrice << "\n\nOwned Company:\n\n" << *(s.ownedCompany);
};
ostream& operator<<(ostream& strm, const Transaction& t) {
    string type = (t.type) ? ("+") : ("-");
    strm << "Margin: " << type << t.cost << "\tTransaction Time: " << t.currentTime << "\n\n";
    return strm;
};
ostream& operator<<(ostream& strm, const Company& c) {
    return strm << "\tName: " << c.companyName << "\n\n\tType: " << c.companyType << "\n\n";
};
