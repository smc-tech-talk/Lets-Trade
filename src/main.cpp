/* Every header files working in progress here */
#include "../include/public_header.hpp"
#include "stock.cpp"
#include "csvExtractor.cpp"
#include "banking.cpp"
#include "player.cpp"
#include "transaction.cpp"
#include <memory>

vector< std::unique_ptr<Stock> > CreateStocks(int howMany);  // Should return vecotr<Stock*> later
int main(){

    /* Initializing Data */
    srand(time(NULL));
    bool isPlaying, isDay, isTrade = true;
    Date* official_date = new Date();

    /* Create Stocks */
    auto stocks = CreateStocks(15);
    for (auto& s: stocks)
        cout << *s << endl;

    /* Generate Player */

    /* Genertate BankAccount */

    /* Main Loop */
    while(isPlaying){

        while(isDay){

            while(isTrade){
                // Print Current Time()
                // Print Positions
                // Print Balance
                // Print All Stocks
                /*
                swtich(first_decision){
                    case:
                        break;
                    case:
                        break;
                    case:
                        break;
                    case:
                        break;
                }*/
                // If trade ends
                Date::AddGameTime(official_date);
                isTrade = false;
            }
        }
    }




    /* Generate Player */
    // auto player = new Player(name, ...);

    while(isPlaying){

        /* codes ... */
        isPlaying = false;
    }

    system("pause");
    return 0;
}

vector<std::unique_ptr<Stock>> CreateStocks(int howMany){
    int count;
    vector<std::unique_ptr<Stock>> stocks;
    auto e = std::make_unique<CSVExtractor>("./companies.csv");
    auto r = std::make_unique<RandomNumberGenerator>(1, 400, howMany);
    auto data = e->GetResult();
    auto manyIndex = r->GetNumbers();

    for(int i = 0; i < manyIndex.size(); i++){
        count = manyIndex.at(i);

        Company* c = new Company(data.at(count).at(1), data.at(count).at(2)); // This will be handled by ~Stock()
        auto s = std::make_unique<Stock>(data.at(count).at(0), c);
        stocks.push_back(std::move(s)); // emplace_back() does not work
    }
    return stocks;
}
