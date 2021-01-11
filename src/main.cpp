/* Every header files working in progress here */
#include "../include/public_header.hpp"
#include "stock.cpp"
#include "csvExtractor.cpp"

int main(){

    srand(time(NULL));
    vector<vector<string>> v;
    vector<int> vv;

    CSVExtractor* c = new CSVExtractor("../src/companies.csv");
    RandomNumberGenerator* n = new RandomNumberGenerator(1, 10, 3);

    v = c->GetResult();
    vv = n->GetNumbers();

    // CSVExtractor
    for(std::size_t i = 0; i < v.size(); i++){
        for(int j = 0; j < 3; j++){
            switch (j) {
                case 0: cout << "Symbol:\t"; break;
                case 1: cout << "Name:\t"; break;
                case 2: cout << "Type:\t"; break;
            }
             cout << v.at(i).at(j) << endl;
        }
    }

    // GenerateRandomNumbers
    for(std::size_t i = 0; i < vv.size(); i++)
        cout << vv.at(i) << endl;

    Stock* s  = new Stock("Ben's ");
    cout << s->GetChangedPercentage() << endl; // => 0%
    s->SetCurrentPrice(214.00);
    s->UpdateStockPrice();
    cout << s->GetChangedPercentage() << endl;

    delete s;
    s = NULL;

    delete c;
    c = NULL;

    delete n;
    n = NULL;

    return 0;
}
