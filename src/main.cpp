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
vector< std::unique_ptr<Stock> > CreateStocks(int howMany, double stockPrice[]); // Should return vecotr<Stock*> later
void InitializeStockPrice(double stockPrice[], const int quantity);
double GetRandomPrice(int rand);
double GetRandomPrice(double price);
void UpdateStockPrice(const vector<std::unique_ptr<Stock>>& stocks);
void PrintStart(const std::unique_ptr<Date>& date);
void PrintDay(int day, const std::unique_ptr<Date>& date, Account& account);
void PrintTradeMenu(const std::unique_ptr<Date>& date);
void PrintPortfolioDemo();
void PrintPortfolio(Account& account, Player& player);
void PrintDayChange(Account& account);
void PrintStockLists(const std::unique_ptr<Stock>& stocks);
void PassTime(const std::unique_ptr<Date>& date);
void NoPassTime(const std::unique_ptr<Date>& date);

// main
int main(){

    int PAUSE;
    const int STOCK_QUANTITY = 15;
    double stockPrice[STOCK_QUANTITY];
    srand(time(NULL));
    static int day = 1;
    bool isPlaying = true, isDay = true, isTrade = true;
    auto game_time = std::make_unique<Date>();

    string name;
    int age;
    auto official_date = std::make_unique<Date>();
    InitializeStockPrice(stockPrice, STOCK_QUANTITY);
    auto stocks = CreateStocks(STOCK_QUANTITY, stockPrice);

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
            PrintDay(day, game_time, *account);
            PrintPortfolio(*account, *player);


            while(isTrade){

                int userInput = 0;
                PrintTradeMenu(game_time);
                GetUserInput(userInput, "Enter Your Choice");

                // ***Segmentation error at 15:00***

                // Trade Menu
                switch(userInput){

                    case 1:{    // 1. Display Stock Lists
                        int i = 1;
                        for(auto& s: stocks)
                            std::cout << i << ". " << s.get()->GetSymbol() << std::endl;

                        // will be rewritten as PrintStockLists(stocks);
                        PassTime(game_time);
                        break;
                    }
                    case 2:{    // 2. Buy Stocks
                        int stockIndex;
                        int quantity;
                        GetUserInput(stockIndex, "Stock");
                        GetUserInput(quantity, "Quantity");
                        portfolio->BuyShare(stocks.at(stockIndex - 1).get(), quantity);
                        break;
                    }
                    case 3:{    // 3. Sell Stocks
                        int stockIndex;
                        int quantity;
                        GetUserInput(stockIndex, "Stock");
                        GetUserInput(quantity, "Quantity");
                        portfolio->SellShare(stocks.at(stockIndex).get(), quantity);
                        PassTime(game_time);
                        break;
                    }
                    case 4:{    // 4. Print portfolio
                        // ***segmentation error***
                        PrintPortfolio(*account, *player);
                        NoPassTime(game_time);
                        break;
                    }
                    case 5:{    // 5. Check Bank Account

                        account->info_Account();
                        NoPassTime(game_time);
                        break;

                    case 6:{    // 6. Quit the Game
                        // GameOver();
                    }

                    default:{
                        std::cerr << "No time passed. Choose one from the following menu." << std::endl;
                    }

                    }
                }
                if(userInput == 2 || userInput == 3)
                {
                    Date::AddGameTime(*(game_time));
                    UpdateStockPrice(stocks);
                }
                std::cout << "Current Hour: "<< game_time->GetHour() << ":00 " << ((game_time->GetHour() < 12) ? "AM" : "PM") << std::endl;
                if((game_time->GetHour() == 9) && (userInput == 2 || userInput == 3))
                    isTrade = false;

                std::cout << "Time passed! Current time is "<< game_time->GetHour() << ":00 " << ((game_time->GetHour() < 12) ? "AM" : "PM") << std::endl;
            }
            isDay = false;
        }
        isPlaying = false;
    }

    delete portfolio;
    portfolio = NULL;

    return 0;
}

vector<std::unique_ptr<Stock>> CreateStocks(int howMany, double stockPrice[]){
    int count;
    vector<std::unique_ptr<Stock>> stocks;
    auto e = std::make_unique<CSVExtractor>("./companies.csv");
    auto r = std::make_unique<RandomNumberGenerator>(1, 400, howMany);
    auto data = e->GetResult();
    auto manyIndex = r->GetNumbers();

    for(int i = 0; i < manyIndex.size(); i++){
        count = manyIndex.at(i);
        Company* c = new Company(data.at(count).at(1), data.at(count).at(2)); // This will be handled by ~Stock()
        // Use Stock::Stock(string s, double p, Company* c)
        auto s = std::make_unique<Stock>(data.at(count).at(0), stockPrice[i], c);
        stocks.push_back(std::move(s)); // emplace_back() does not work
    }
    return stocks;
}

/* Stock Price Functions */
void InitializeStockPrice(double stockPrice[], const int quantity){
    for(int i = 0; i < quantity; i++){
        stockPrice[i] = GetRandomPrice(100);
        std::cout << "INITIALIZED" << stockPrice[i] << std::endl;
    }
}

void UpdateStockPrice(const vector<std::unique_ptr<Stock>>& stocks){
    for(auto& s : stocks){
        s.get()->UpdateStockPrice(GetRandomPrice(s.get()->GetCurrentPrice()));
    }
    std::cout << "Stock Price Updated" << std::endl;
}

template <typename T>
void GetUserInput(T& arg, const std::string msg){
    cout << msg << ": \n";
    cin >> arg;
}

/* Random Functions */
double GetRandomPrice(int randNum){ return (rand() % randNum); };
double GetRandomPrice(double price){
    return ((GetRandomPrice(100) * 0.01) * GetRandomPrice(100) * 0.01) * 100;
};

void DisplayMessage(const std::string msg){
    cout << msg << " \n";
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
}
void PrintDay(int day, const std::unique_ptr<Date>& date, Account& account){
    std::cout << "\n――――――――――――――――――――――――――――――――――――――――| Day " << day << " |――――――――――――――――――――――――――――――――――――――――――\n" << std::endl;
    std::cout << "\t\t\t  Current Game Time: " << *date << std::endl;
    // add day(Monday etc)
    // std::cout << "\nBalance: $" << account.get_balance() << std::endl;
}
void PrintTradeMenu(const std::unique_ptr<Date>& date){
    std::cout << "\n==========Main Menu=========== " << endl;
    std::cout << "Current Game Time: " << date->GetHour() << ":00\n" << std::endl;
    std::cout << " 1. Display Stock Lists" << endl;
    std::cout << " 2. Buy Stocks" << endl;
    std::cout << " 3. Sell Stocks" << endl;
    std::cout << " 4. Check Portfolio" << endl;
    std::cout << " 5. Check Bank Account" << endl;
    std::cout << " 6. Quit the Game" << endl;
    std::cout << "=============================" << std::endl;
    std::cout << "\n"<< std::endl;
}


void PrintPortfolio(Account& account, Player& player){
    std::cout << "\t\t==========================================================" << std::endl;
    std::cout << "\t\t\t   ≣≣≣≣≣≣≣≣≣≣" << player.GetName() << "'s Portfolio:" << "≣≣≣≣≣≣≣≣≣≣" << std::endl;
    std::cout << "\t\t\t   Balance: " << account.get_balance() << " || " << "Day Change: ";
    PrintDayChange(account);
    std::cout << "\n\t\t----------------------------------------------------------" << std::endl;
    std::cout << "\t\t\t   Symbol" << "\t\t" << "Position" << std::endl;
    for(auto& s : player.GetPortfolio().GetShares()){
        std::cout << "\t\t\t   " << s.GetStockPtr()->GetSymbol() << "\t\t\t   " << s.GetPosition() << std::endl;
    }
    std::cout << "\t\t==========================================================\n" << std::endl;
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
    std::cout << "Which stock would you like to purchase?\n" << std::endl;
    for(auto& s: stocks){
        std::cout << "\t" << i << ". " << s.get()->GetSymbol() << ":" << " $" << s.get()->GetCurrentPrice() << std::endl;
        i++;
    }
}


void PassTime(const std::unique_ptr<Date>& game_time){
    std::cout << "\nAction executed! Press Any Key to Continue\n";
    int PAUSE;
    std::cin >> PAUSE;
    Date::AddGameTime(*(game_time));
    std::cout << "Time passed! Current time is "<< game_time->GetHour() << ":00 " << ((game_time->GetHour() < 12) ? "AM" : "PM") << std::endl;
}

void NoPassTime(const std::unique_ptr<Date>& game_time){
    std::cout << "\nAction executed! Press Any Key to Continue\n";
    int PAUSE;
    std::cin >> PAUSE;
    Date::AddGameTime(*(game_time));
    std::cout << "No time passed! Current time is "<< game_time->GetHour() << ":00 " << ((game_time->GetHour() < 12) ? "AM" : "PM") << std::endl;
}
