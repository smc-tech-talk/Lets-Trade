/* Every header files working in progress here */
#include "../include/public_header.hpp"
#include "stock.cpp"
#include "csvExtractor.cpp"
#include "player.cpp"


int main(){

    /* Initializing Data */
    srand(time(NULL));
    vector<vector<string>> v;
    vector<int> vv;
    CSVExtractor* c = new CSVExtractor("companies.csv");
    RandomNumberGenerator* n = new RandomNumberGenerator(1, 30, 15);

    /* Get Resources */
    v = c->GetResult();
    vv = n->GetNumbers();

    /* Delete Pointers */

    delete c;
    c = NULL;

    delete n;
    n = NULL;

    system("pause");
    return 0;
}
