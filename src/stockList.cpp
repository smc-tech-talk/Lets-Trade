#include "stockList.hpp"

void StockList::GenerateStocks(string filePath){
    ifstream myFile;
    string line;
    myFile.open(filePath);
    cout << myFile.good() << endl;
    while (myFile.good()){
        getline(myFile, line, ',');
        cout << line << endl;
        line = "";
    }

    myFile.close();
};
