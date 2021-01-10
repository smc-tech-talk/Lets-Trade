/* Include */
#include "stock.hpp"
time_t NOW = time(0); // current system date/time
double INITIAL_STOCK_PRICE = -10000; //

/* Transaction */
Transaction::Transaction(int t, double c){
    currentTime = ctime(&NOW);  // convert in string form
    type = t;
    cost = c;
};

/* Company */
Company::Company(string n) // Test
    :companyName(n){};
Company::Company(string n, string t)
    :companyName(n),
    companyType(t),
    companyPrice(0.00),
    companyValue(0.00){};

/* Stock */
Stock::Stock(string s) // Test
    :stockSymbol(s),
    stockPrevPrice(INITIAL_STOCK_PRICE),
    stockIssuer(NULL){};
Stock::Stock(string s, double p, Company* c)
    :stockSymbol(s),
    stockCurrentPrice(p),
    stockPrevPrice(INITIAL_STOCK_PRICE),
    stockIssuer(c){};

// Get
double Stock::GetCurrentPrice(){ return stockCurrentPrice; };
double Stock::GetPrevPrice(){ return stockPrevPrice; };
string Stock::GetSymbol(){ return stockSymbol; };
vector<Transaction> Stock::GetTransactionHistory(){ return transactionHistory; };
Company Stock::GetStockIssuer(){ return *stockIssuer; }; // Return Object(Not pointer)

// Set
void Stock::SetCurrentPrice(double cp){ stockCurrentPrice = cp; };
void Stock::SetPrevPrice(double pp){ stockPrevPrice = pp; };
void Stock::SetSymbol(string s){ stockSymbol = s; };
void Stock::SetStockIssuer(Company* c){ stockIssuer =  c; };

// Methods
void Stock::AddTransactionHistory(int type,  double cost){
    Transaction t(type, cost);
    transactionHistory.push_back(t);
    // ChangeStockPrice
};
int Stock::GetRandomNumber(int num){ return (rand() % num); };
double Stock::GetChangedPercentage(){
    if(stockPrevPrice == INITIAL_STOCK_PRICE)
        return 0.00;
    else
        return ( 100 * (stockPrevPrice - stockCurrentPrice) ) / stockCurrentPrice;
};

// In Progress
double Stock::GetRandomStockPrice(int i){
    int r = GetRandomNumber(i);
    double result = (rand() % r);
    return result;
};
void Stock::UpdateStockPrice(double){

    // codes here
};

// Tests
void Stock::PrintTransactionHistory(){
    for(auto& t : transactionHistory)
        cout << t;
};

// Destructor
Stock::~Stock(){
    delete stockIssuer;
    stockIssuer = NULL;
};

// String Representation of the object
ostream& operator<<(ostream& strm, const Stock& s) {
    return strm << "\n\n" << "Stock Symbol: " << s.stockSymbol << "\n\nCurrent Price: $" << s.stockCurrentPrice << "\n\nOwned Company:\n\n" << *(s.stockIssuer);
};
ostream& operator<<(ostream& strm, const Transaction& t) {
    string type = (t.type) ? ("+") : ("-");
    strm << "Margin: " << type << t.cost << "\tTransaction Time: " << t.currentTime << "\n\n";
    return strm;
};
ostream& operator<<(ostream& strm, const Company& c) {
    return strm << "\tName: " << c.companyName << "\n\n\tType: " << c.companyType << "\n\n";
};
