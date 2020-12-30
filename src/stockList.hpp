#include <fstream>
#include <tuple>
#include <sstream>
#include "stock.hpp"

class StockList{
public:
    vector<Stock*> GenerateStocks();
    void ChangeAllStockPrice();
    vector<tuple<string, string, string>> ExtractData(string);
};
