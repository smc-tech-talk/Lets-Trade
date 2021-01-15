/* Every header files working in progress here */
#include "../include/public_header.hpp"
#include "stock.cpp"
#include "csvExtractor.cpp"
#include "banking.cpp"

int main(){

    /* Initializing Data */

    srand(time(NULL));
    string username;
    vector<vector<string>> v;
    vector<int> vv;
    CSVExtractor* c = new CSVExtractor("companies.csv");
    RandomNumberGenerator* n = new RandomNumberGenerator(1, 40, 15);
    // Generate stocks
    cout << "Input user name\n" << endl;
    cin >> username;
    Account* a = new Account(username, 9);
    a->info_Account(*a);
    cout << "Hello World" << endl;

    v = c->GetResult();
    vv = n->GetNumbers();
    cout << v.at(2).at(1) << endl;

    delete c;
    delete n;
    delete a;

    c=NULL;
    n=NULL;
    a=NULL;

    return 0;
}
