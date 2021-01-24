/* Every header files working in progress here */
#include "../include/public_header.hpp"
#include "stock.cpp"
#include "csvExtractor.cpp"
#include "banking.cpp"
#include "player.cpp"
#include "transaction.cpp"

void CreateStocks(int howMany); // Should return vecotr<Stock*> later
int main(){

    /* Initializing Data */
    srand(time(NULL));
    CreateStocks(30);

    Date* d = new Date(); // => Exact current time

    system("pause");

    return 0;
}

void CreateStocks(int howMany){ // Should return vector<Stock*> later
    int count;
    std::vector<int> manyIndex;
    CSVExtractor* e = new CSVExtractor("./companies.csv");
    RandomNumberGenerator* r = new RandomNumberGenerator(1, 100, howMany);
    auto result = e->GetResult();
    manyIndex = r->GetNumbers();

    for(int i = 0; i < manyIndex.size(); i++){
        count = manyIndex.at(i);

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
