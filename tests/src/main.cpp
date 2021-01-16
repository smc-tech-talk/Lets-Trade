/* Every header files working in progress here */
#include "../include/public_header.hpp"
#include "stock.cpp"
#include "csvExtractor.cpp"
#include "banking.cpp"
#include "player.cpp"

int main(){

    /* Initializing Data */
    srand(time(NULL));
    string username;
    vector<vector<string>> data;
    vector<int> index;
    CSVExtractor* c = new CSVExtractor("companies.csv");
    RandomNumberGenerator* n = new RandomNumberGenerator(1, 40, 15);

    // Generate bank Account
    cout << "Input user name\n" << endl;
    cin >> username;
    Account* a = new Account(username, 9);
    a->info_Account(*a);
    cout << "Hello World" << endl;

    // Generate stocks
    // GenerateStocks();

    data = c->GetResult();
    index = n->GetNumbers();

    delete c;
    delete n;
    c=NULL;
    n=NULL;

    /* End of the game */
    delete a;
    a=NULL;

    system("pause");
    return 0;
}

/* Initializers */
vector<Company*> GenerateCompanies(){
    vector<Company*> result;
    return result;
}
vector<Stock*> GenerateStocks(){
    vector<Stock*> result;
    return result;
}
