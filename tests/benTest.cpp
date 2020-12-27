/* Every header files working in progress here */
#include "../include/public_header.hpp"
#include "../src/stock.cpp"

int main(){
    Stock* s = new Stock("Ben", "BNWGY", 200.00);
    Company* c = new Company("Ben's", 100.00, 150.00);
    Company* a = new Company("Anna's", 90.00, 70.00);
    vector<Transaction> t;
    //s->PrintStock();
    s->SetCompany(c);
    s->SetCompany(a);
    delete s;
    delete c;
    delete a;
    s->GetName();
    s->GetPrice();

    s->AddTransactionHistory(BUY, 200.00);
    s->AddTransactionHistory(SELL, 150.00);
    s->AddTransactionHistory(BUY, 4640.00);

    s->PrintTransactionHistory();
    t = s->GetTransactionHistory();
    cout << t.at(0) << endl;
    s = NULL;
    c = NULL;
    a = NULL;
    return 0;
}
