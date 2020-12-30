/* Every header files working in progress here */
#include "../include/public_header.hpp"
#include "../src/stock.cpp"
#include "../src/stockList.cpp"

int main(){
    /*Stock* s = new Stock("Ben", "BNWGY", 200.00);
    Company* c = new Company("Ben's", 100.00, 150.00);
    Company* a = new Company("Anna's", 90.00, 70.00);

    //s->SetCompany(c);
    //s->SetCompany(a);
    delete s;
    delete c;
    delete a;


    s = NULL;
    c = NULL;
    a = NULL;*/
    vector<tuple<string, string, string>> t;
    StockList s;
    t = s.ExtractData("../src/companys.csv");
    cout << get<1>(t.at(1)) << endl;


    return 0;
}
