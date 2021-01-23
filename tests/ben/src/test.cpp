/* Every header files working in progress here */
#include "../include/public_header.hpp"
#include "stock.cpp"
#include "csvExtractor.cpp"
#include "banking.cpp"
#include "player.cpp"
#include "transaction.cpp"
//#include "player.cpp"

void CreateStocks();
int main(){
    /* Initializing Data */
    srand(time(NULL));
    /*Date* d = new Date();
    Transaction t(STOCK_BUY, 200, *d);
    Transaction t2(STOCK_SELL, 45.05, *d);
    Transaction t3(STOCK_BUY, 105.680, *d);

    vector<Transaction> v;
    Transaction::AddTransaction(v, t);
    Transaction::AddTransaction(v, t2);
    Transaction::AddTransaction(v, t3);

    for(auto& t: v){
        cout << t << endl;
    }*/
    CreateStocks();
    //delete d;
    //d=NULL;

    return 0;
}

void CreateStocks(){
    std::vector<int> index;
    CSVExtractor* e = new CSVExtractor("./companies.csv");
    RandomNumberGenerator* r = new RandomNumberGenerator(40, 200, 15);
    auto result = e->GetResult();
    index = r->GetNumbers();
    int count;

        for(int i = 0; i < index.size(); i++){
        count = index.at(i);
            for (int j = 0; j < 3; j++)
                cout << result.at(count).at(j) << endl;
            cout << "\n" << endl;
        }

    // Things to do
    // 1. Make Company* c = new Company(string name, string type);
    // 2. Make Stock* s = new Stock(string symbol, Company* c)
    // 3. Push pointer to the vector vector<Stock*>
    // 4. Company pointers will be handled by ~Stock()

    delete e;
    delete r;
    e=NULL;
    r=NULL;
}
