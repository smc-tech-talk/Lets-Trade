#include "../include/public_header.hpp"
#include "stock.hpp"
#include "transaction.hpp"
#include "csvExtractor.hpp"
#include "player.hpp"
#include "portfolio.hpp"
#include "banking.hpp"
#include <memory>

void DisplayMessage(const std::string msg);
template<typename T>
void GetUserInput(T &arg, const std::string msg);
vector< std::unique_ptr<Stock> > CreateStocks(int howMany); // Should return vecotr<Stock*> later
void PrintStart(const std::unique_ptr<Date>& date);
void PrintDay(int day, Account& account);
void PrintTrade();
void PrintPortfolioDemo();
void PrintPortfolio(Account& account, Player& player);
void PrintDayChange(Account& account);
void PrintStockLists(const std::unique_ptr<Stock>& stocks);

// main
int main(){

    int PAUSE;
    srand(time(NULL));
    static int day = 1;
    bool isPlaying = true, isDay = true, isTrade = true;
    auto game_time = std::make_unique<Date>();

    string name;
    int age;
    auto official_date = std::make_unique<Date>();
    auto stocks = CreateStocks(15);

    Player* player;
    Account* account;
    Portfolio* portfolio = new Portfolio(stocks);

    DisplayMessage("Welcome, Enter Player Info to Start");
    GetUserInput<std::string&>(name, "Enter Your Name");
    GetUserInput<int&>(age, "Enter Your Age");

    player = new Player(name, age, portfolio);
    account = new Account(player);
    account->add_balance(0);


    while(isPlaying){
        PrintStart(game_time);
        while(isDay){
            PrintDay(day, *account);
            PrintPortfolio(*account, *player);

            
            while(isTrade){

                int userInput = 0;
                PrintTrade();
                GetUserInput(userInput, "Enter Your Choice");

                // Trade Menu
                switch(userInput){

                    case 1:{    // 1. Display Stock Lists
                        int i = 1;
                        for(auto& s: stocks)
                            std::cout << i << ". " << s.get()->GetSymbol() << std::endl;

                        // will be rewritten as PrintStockLists(stocks);
                        break;
                    }
                    case 2:{    // 2. Buy Stocks
                        int stockIndex;
                        int quantity;
                        GetUserInput(stockIndex, "Stock");
                        GetUserInput(quantity, "Quantity");
                        portfolio->BuyShare(stocks.at(stockIndex).get(), quantity);
                        break;
                    }
                    case 3:{    // 3. Sell Stocks
                        int stockIndex;
                        int quantity;
                        GetUserInput(stockIndex, "Stock");
                        GetUserInput(quantity, "Quantity");
                        portfolio->SellShare(stocks.at(stockIndex).get(), quantity);
                        break;
                    }
                    case 4:{    // 4. Check Bank Accoun
                    
                        //Portfolio::PrintPortfolio(userInput);
                        break;

                    }
                    case 5:{    // 5. Check Bank Account

                        account->info_Account();
                        break;

                    }
                }
                std::cout << "Current Hour: "<< game_time->GetHour() << ":00 " << ((game_time->GetHour() < 12) ? "AM" : "PM") << std::endl;
                std::cin >> PAUSE;
                std::cout << "1 Selected!\n" << endl;
                Date::AddGameTime(*(game_time));
                //PrintPortfolioDemo2(100, *player);
                if(game_time->GetHour() == 9)
                    isTrade = false;
            }
            isDay = false;
        }
        isPlaying = false;
    }

    delete player;
    delete portfolio;
    player = NULL;
    portfolio = NULL;

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


void DisplayMessage(const std::string msg){
    cout << msg << " \n";
}

template <typename T>
void GetUserInput(T& arg, const std::string msg){
    cout << msg << ": \n";
    cin >> arg;
}

/* All Console Printing Functions Here */
void PrintStart(const std::unique_ptr<Date>& date){
    std::cout << "\n" << std::endl;
    std::cout << "\t\t\t********************************************" << std::endl;
    std::cout << "\t\t\t\t\tWelcome to" << std::endl;
    std::cout << " __                  __   __                 ________                         __           " << std::endl;
    std::cout << "|  \\                |  \\ |  \\               |        \\                       |  \\          " << std::endl;
    std::cout << "| $$       ______  _| $$_| $$ _______        \\$$$$$$$$______   ______    ____| $$  ______  " << std::endl;
    std::cout << "| $$      /      \\|   $$ \\$ /       \\         | $$  /      \\ |      \\  /      $$ /      \\ " << std::endl;
    std::cout << "| $$     |  $$$$$$\\\\$$$$$$  |  $$$$$$$         | $$ |  $$$$$$\\ \\$$$$$$\\|  $$$$$$$|  $$$$$$\\" << std::endl;
    std::cout << "| $$     | $$    $$ | $$ __  \\$$    \\          | $$ | $$   \\$$/      $$| $$  | $$| $$    $$" << std::endl;
    std::cout << "| $$_____| $$$$$$$$ | $$|  \\ _\\$$$$$$\\         | $$ | $$     |  $$$$$$$| $$__| $$| $$$$$$$$" << std::endl;
    std::cout << "| $$     \\\\$$    \\  \\$$  $$|       $$          | $$ | $$      \\$$    $$ \\$$    $$ \\$$     \\" << std::endl;
    std::cout << " \\$$$$$$$$ \\$$$$$$$   \\$$$$  \\$$$$$$$           \\$$  \\$        \\$$$$$$$  \\$$$$$$$  \\$$$$$$$" << std::endl;
    std::cout << "\n\t\t\t\tPowered by SMC Tech Talk Team 2021" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "\t\t\t********************************************" << std::endl;
    std::cout << "\n\t\t\t  Current Game Time: " << *date << std::endl;
}
void PrintDay(int day, Account& account){
    std::cout << "\n" << std::endl;
    std::cout << "\t\t\t\t\t| Day " << day << " |" << std::endl;
    std::cout << "\n"<< std::endl;
    std::cout << "\tYour Balance: $" << account.get_balance() << std::endl;
}
void PrintTrade(){
    std::cout << "\n\t==========Main Menu=========== \n" << endl;
    std::cout << "\t1. Display Stock Lists" << endl;
    std::cout << "\t2. Buy Stocks" << endl;
    std::cout << "\t3. Sell Stocks" << endl;
    std::cout << "\t4. Check Portfolio" << endl;
    std::cout << "\t5. Check Bank Account" << endl;
    std::cout << "\t=============================" << std::endl;
    std::cout << "\n"<< std::endl;
}
void PrintPortfolioDemo(){
    std::cout << "\nThis is portfolio demo version\n" << std::endl;
    std::cout << "=============================" << std::endl;
    std::cout << "Income: " << std::endl;
    std::cout << "\nLoss: " << std::endl;
    std::cout << "\nBalance: " << std::endl;
    std::cout << "=============================" << std::endl;
}


void PrintPortfolio(Account& account, Player& player){
    std::cout << "\n" << player.GetName() << "'s Portfolio:\n" << std::endl;
    std::cout << "=============================" << std::endl;
    std::cout << "Balance: " << account.get_balance() << std::endl;
    std::cout << "\nDay Change: "  << std::endl;
    PrintDayChange(account);
    std::cout << "\n=============================" << std::endl;
    for(auto& s : player.GetPortfolio().GetShares())
        std::cout << "Symbol: " << s.GetStock().GetSymbol() << std::endl;
}

void PrintDayChange(Account& account){
    double dayChange = 0;
    double dayChangePercentage = 0;
    dayChange = account.get_balance() - account.get_previous_balance();
    dayChangePercentage = account.get_balance() / account.get_previous_balance();
    std::cout << dayChange;
    /*if(!isinf(dayChangePercentage))
        std::cout << "(" << dayChangePercentage << "%)" << std::endl;
    else
        std::cout << "(-%)" << std::endl;*/
}

void PrintStockLists(const vector<std::unique_ptr<Stock>>& stocks){
    int i = 1;
    for(auto& s: stocks)
        std::cout << i << ". " << s.get()->GetSymbol() << std::endl;
}
