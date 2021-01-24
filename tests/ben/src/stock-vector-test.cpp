/* Every header files working in progress here */
#include "../include/public_header.hpp"
#include "stock.cpp"
#include "csvExtractor.cpp"
#include "banking.cpp"
#include "player.cpp"
#include "transaction.cpp"

vector<Stock*> CreateStocks(int howMany); // Should return vecotr<Stock*> later
int main(){

    /* Initializing Data */
    srand(time(NULL));
    auto v = CreateStocks(30);

    // Delete pointers in the vector before the program ends
    for(auto& item: v){
        cout << *item << endl;
        delete item;
        item = NULL;
    }

    system("pause");
    return 0;
}


/* Main funtions */
vector<Stock*> CreateStocks(int howMany){ // Should return vector<Stock*> later
    int count;
    string symbol, name, type;

    std::vector<int> manyIndex;
    std::vector<Stock*> stocks;
    
    CSVExtractor* e = new CSVExtractor("./companies.csv");
    RandomNumberGenerator* r = new RandomNumberGenerator(1, 100, howMany);
    auto result = e->GetResult();
    manyIndex = r->GetNumbers();

    for(int i = 0; i < manyIndex.size(); i++){
        count = manyIndex.at(i);

        // symbol/name/type
        for (int j = 0; j < 3; j++)
            switch (j) {
                case 0: symbol = result.at(count).at(j); break;
                case 1: name = result.at(count).at(j); break;
                case 2: type = result.at(count).at(j); break;
            }

        // Create Company
        Company* c = new Company(name, type);

        // Create Stock
        Stock* s = new Stock(symbol, c);

        // Reset Values
        symbol, name, type = "";

        // Push stock* to stocks
        stocks.push_back(s);
    }

    // Delete used pointers
    delete e;
    delete r;
    e = NULL;
    r = NULL;

    return stocks;
}
