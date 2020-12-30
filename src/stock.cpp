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

Company::Company(string n, string t, double p, double v)
    :companyName(n),
    companyType(t),
    companyPrice(p),
    companyValue(v){};

/* Stock */
Stock::Stock(string s)
    :stockSymbol(s){};

Stock::Stock(string s, double p, Company* c)
    :stockSymbol(s),
    stockCurrentPrice(p),
    ownedCompany(c){};

// Get
double Stock::GetPrice(){ return stockCurrentPrice; };
vector<Transaction> Stock::GetTransactionHistory(){ return transactionHistory; };
Company Stock::GetOwnedCompany(){ return *ownedCompany; };

// Set
void Stock::SetPrice(double p){ stockCurrentPrice = p; };
void Stock::SetCompany(Company* c){ ownedCompany =  c; };

// Methods
/*double Stock::PriceChangeRate(){

};*/
string Stock::UpOrDown(){
    string symbol;
    if(!stockPrevPrice){
        return "No previous price of the stock";
    }else if(stockPrevPrice == stockCurrentPrice){
        symbol = "=";
    }else{
        bool margin = ((stockCurrentPrice - stockPrevPrice) > 0);
        if(margin)
            return "+";
        else
            return "-";
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
    return strm << "String Representation of Stock Object: \n\n";
};
ostream& operator<<(ostream& strm, const Transaction& t) {
    string type = (t.type) ? ("+") : ("-");
    strm << "Margin: " << type << t.cost << "\tTransaction Time: " << t.currentTime << "\n\n";
    return strm;
};
ostream& operator<<(ostream& strm, const Company& c) {
    return strm << "String Representation of Company Object: \n\n";
};
