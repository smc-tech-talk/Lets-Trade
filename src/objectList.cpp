#include "objectList.hpp"

/* ObjectList */
template<typename T>
ObjectList<T>::~ObjectList(){
    for(int i = 0; i < list.size(); i++)
        delete list.at(i);
};

// Get
template<typename T>
vector<T*> ObjectList<T>::GetList(){ return list; };

// Methods
template<typename T>
vector<tuple<string, string, string>> ObjectList<T>::ExtractData(string filePath){
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
                //cout << get<0>(tm) << "\t" << get<1>(tm) << "\t" << get<2>(tm) << endl;
                colIdx = 1;
            }else{ colIdx++; }
        }
    }
    myFile.close();
    return result;
};

/* StockList */
StockList::StockList(string filePath){
    this->GenerateStocks(filePath);
};

//
vector<Stock*> StockList::GenerateStocks(string filePath){
    string symbol, name, type;
    double stockPrice = 0;
    vector<Stock*> result;
    vector<tuple<string, string, string>> data;

    data = this->ExtractData(filePath);

    for(int i = 0; i < data.size(); i++){

        // Create Company Object
        name = get<1>(data.at(i));
        type = get<2>(data.at(i));
        Company* c = new Company(name, type);

        // Create Stocks Object
        symbol = get<0>(data.at(i));
        Stock* s = new Stock(symbol, stockPrice, c);

        list.push_back(s);
    }

    return result;
};
