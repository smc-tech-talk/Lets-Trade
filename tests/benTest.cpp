/* Every header files working in progress here */
#include "../include/public_header.hpp"
#include "../src/stock.cpp"
#include "../src/objectList.cpp"

int main(){
    /* StockList* s = new StockList("../src/companies.csv");
    cout << *(s->GetList().at(3)) << endl;
    delete s;
    s = NULL; */
    Stock* s = new Stock("ben");
    cout << s->GetRandomStockPrice(1,1) << endl;
    delete s;
    s = NULL;
    return 0;
}
