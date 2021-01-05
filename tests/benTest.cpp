/* Every header files working in progress here */
#include "../include/public_header.hpp"
#include "../src/stock.cpp"
#include "../src/objectList.cpp"

int main(){

    StockList* slist = new StockList("../src/companies.csv");
    //s = slist->at(3); //3rd element of the list

    cout << *(slist->GetList().at(3)) << endl; // Gives us 3rd element of stock array

    delete slist;
    slist = NULL;
    return 0;
}
