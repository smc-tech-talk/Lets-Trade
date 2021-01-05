#include <fstream>
#include <tuple>
#include <sstream>
#include "stock.hpp"

template<typename T>
class ObjectList{
public:
    // Get
    vector<T*> GetList();
    ~ObjectList();
protected:
    vector<tuple<string, string, string>> ExtractData(string);
    vector<T*> list;
};

class StockList: public ObjectList<Stock>{
public:
    StockList(string);
    vector<Stock*> GenerateStocks(string);
    void UpdateStockPrice(); // one
    void UpdateEveryStockPrice(); // whole
};