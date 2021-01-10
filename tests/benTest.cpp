/* Every header files working in progress here */
#include "../include/public_header.hpp"
//#include "../src/stock.cpp"
//#include "../src/objectList.cpp"
#include "../src/csvExtractor.cpp"

int main(){

    CSVExtractor* c = new CSVExtractor("../src/companies.csv");
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
