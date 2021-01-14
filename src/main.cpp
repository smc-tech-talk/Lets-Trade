/* Every header files working in progress here */
#include "../include/public_header.hpp"
#include "stock.cpp"
#include "csvExtractor.cpp"

int main(){

    /* Initializing Data */
    srand(time(NULL));
    vector<vector<string>> v;
    vector<int> vv;
    CSVExtractor* c = new CSVExtractor("companies.csv");
    RandomNumberGenerator* n = new RandomNumberGenerator(1, 10, 15);
    

    v = c->GetResult();
    vv = n->GetNumbers();

    delete c;
    c = NULL;

    delete n;
    n = NULL;

    system("pause");
    return 0;
}
