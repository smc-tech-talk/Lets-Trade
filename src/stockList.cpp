#include "stockList.hpp"

vector<Stock*> StockList::GenerateStocks(){
    vector<Stock*> result;

    return result;
};

vector<tuple<string, string, string>> StockList::ExtractData(string filePath){
    ifstream myFile;
    vector<tuple<string, string, string>> result;
    tuple<string, string, string> tm;
    string line, word, col1, col2, col3;
    int colIdx = 1;
    myFile.open(filePath);
    while (myFile.good()){
        // read an entire row and
        // store it in a string variable 'line'
        getline(myFile, line);
        stringstream ss(line);
        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(ss, word, ',')) {
            // Store into vector
            // result.push_back(word);
            switch(colIdx){
                case 1: col1 = word; break;
                case 2: col2 = word; break;
                case 3: col3 = word; break;
            }
            if(colIdx == 3){
                tm = make_tuple(col1, col2, col3);
                //cout << col1 << "\t" << col2 << "\t" << col3 << endl;
                result.push_back(tm);
                cout << get<0>(tm) << "\t" << get<1>(tm) << "\t" << get<2>(tm) << endl;
                colIdx = 1;
            }else{ colIdx++; }
        }
    }
    myFile.close();
    return result;
};
