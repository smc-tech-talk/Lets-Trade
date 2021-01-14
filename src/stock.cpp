/* Include */
#include "stock.hpp"
time_t NOW = time(0); // current system date/time
double INITIAL_STOCK_PRICE = -10000;

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
    stockIssuer(NULL){
        this->stockUniqueConstant = (this->GetRandomNumber(4) + 1) * 0.00418953;
        //cout << this->stockUniqueConstant << endl;
    };
Stock::Stock(string s, double p, Company* c)
    :stockSymbol(s),
    stockCurrentPrice(p),
    stockPrevPrice(INITIAL_STOCK_PRICE),
    stockIssuer(c){
        this->stockUniqueConstant = (this->GetRandomNumber(4) + 1) * 0.0418953;
        //cout << this->stockUniqueConstant << endl;
    };

// Get
double Stock::GetCurrentPrice(){ return stockCurrentPrice; };
double Stock::GetPrevPrice(){ return stockPrevPrice; };
double Stock::GetChangedPercentage(){ return stockChangedPercentage; };
string Stock::GetSymbol(){ return stockSymbol; };
vector<Transaction> Stock::GetTransactionHistory(){ return transactionHistory; };
Company Stock::GetStockIssuer(){ return *stockIssuer; }; // Return Object(Not pointer)

// Set
void Stock::SetCurrentPrice(double cp){ stockCurrentPrice = cp; };
void Stock::SetPrevPrice(double pp){ stockPrevPrice = pp; };
void Stock::SetSymbol(string s){ stockSymbol = s; };
void Stock::SetStockIssuer(Company* c){ stockIssuer =  c; };

// Methods
void Stock::UpdateStockPrice(){
    double newStockPrice;
    // codes here
    newStockPrice = GetRandomStockPrice();
    this->stockPrevPrice = this->stockCurrentPrice;
    this->stockCurrentPrice = newStockPrice;
    this->UpdateChangedPercentage();
};
void Stock::AddTransactionHistory(int type,  double cost){
    Transaction t(type, cost);
    transactionHistory.push_back(t);
    // ChangeStockPrice
};
int Stock::GetRandomNumber(int num){ return (rand() % num); };
void Stock::UpdateChangedPercentage(){
    if(this->stockPrevPrice == INITIAL_STOCK_PRICE)
        this->stockChangedPercentage = 0.00;
    else
         this->stockChangedPercentage = ( 100 * (this->stockPrevPrice - this->stockCurrentPrice) ) / this->stockCurrentPrice;
};

// In Progress
double Stock::GetRandomStockPrice(int i){
    int r = GetRandomNumber(i);
    double percentage  = (r * 0.0125 * 0.125) + this->stockUniqueConstant;
    double result;

    // More logic here
    if(rand()%2 == 1 && (this->stockCurrentPrice-this->stockPrevPrice) > 10)
        // Minus
        percentage = percentage * (-1);

    result = this->stockCurrentPrice + (this->stockCurrentPrice * percentage);
    return result;
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
