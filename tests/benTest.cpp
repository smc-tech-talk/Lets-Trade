/* Every header files working in progress here */
#include "../include/public_header.hpp"
//#include "../src/stock.cpp"
//#include "../src/objectList.cpp"
#include "../src/csvExtractor.cpp"



int main(){
    srand(time(NULL));
    vector<vector<string>> v;
    vector<int> vv;
    CSVExtractor* c = new CSVExtractor("../src/companies.csv");
    GenerateRandomNumbers* n = new GenerateRandomNumbers(1, 10, 3);
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

    delete c;
    c = NULL;

    delete n;
    n = NULL;
    /*
    srand(time(NULL));
    vector<Stock*> s_list; // This will store StockList.list
    vector<int> int_list;
	StockList* stocklist_obj = new StockList("../src/companies.csv"); // Create 'list' inside
    int_list = stocklist_obj->GetRandomIndexes(1, 5, 3);
    for(int i = 0; i < int_list.size(); i++)
        cout << int_list.at(i) << endl;

	s_list = stocklist_obj->GetList(); // Store the list
    for(int i = 0; i < int_list.size(); i++)
        cout << *(s_list.at(i)) << endl;
    delete stocklist_obj;
    stocklist_obj = NULL;

    Stock* s  = new Stock("Ben's ");
    cout << s->GetChangedPercentage() << endl; // => 0%
    s->SetCurrentPrice(214.00);
    s->SetPrevPrice(300.00);
    cout << s->GetChangedPercentage() << "%" << endl;

    delete s;
    s = NULL;*/

    return 0;
}
