#include "../include/public_header.hpp"
#include "stock.hpp"
#include "transaction.hpp"
#include "csvExtractor.hpp"
#include "player.hpp"
#include "portfolio.hpp"
#include <memory>

//extern Date* GAME_TIME = new Date();

template<typename T>
void GetUserInput(T &arg, const std::string msg);
vector< std::shared_ptr<Stock> > CreateStocks(int howMany);  // Should return vecotr<Stock*> later
int main(){

    /* Initializing Data */
    srand(time(NULL));
    bool isPlaying, isDay, isTrade = true;
    auto official_date = std::make_unique<Date>();
    Player* player;
    string name;
    int age;
    vector<std::shared_ptr<Stock>> stocks = CreateStocks(15);
    Portfolio* portfolio = new Portfolio(stocks);

    /* Create Stocks */
    //auto stocks = CreateStocks(15);
    GetUserInput<std::string&>(name, "Insert player name");
    GetUserInput<int&>(age, "Insert player age");

    player = new Player(name, age, portfolio);

    portfolio->BuyShare(stocks.at(1).get(), 4);
    portfolio->BuyShare(stocks.at(2).get(), 1);
    portfolio->BuyShare(stocks.at(3).get(), 3);
    portfolio->BuyShare(stocks.at(0).get(), 3);

    /*
    Main Loop
    while(isPlaying){

        while(isDay){

            while(isTrade){
                // Print Current Time()
                // Print Positions
                // Print Balance
                // Print All Stocks

                swtich(first_decision){
                    case:
                        break;
                    case:
                        break;
                    case:
                        break;
                    case:
                        break;
                }
                // If trade ends
                Date::AddGameTime(official_date);
                if(official_date->GetHour() = 9)
                    isTrade = false;
            }
            isDay = false;
        }
        isPlaying = false;
    }
    */
    system("pause");
    //delete player;
    //player = NULL;
    //delete GAME_TIME;
    //GAME_TIME = NULL;

    return 0;
}

vector<std::shared_ptr<Stock>> CreateStocks(int howMany){
    int count;
    vector<std::shared_ptr<Stock>> stocks;
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

template <typename T>
void GetUserInput(T& arg, const std::string msg){
    cout << msg << ": \n";
    cin >> arg;
}
