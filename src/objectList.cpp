#include "objectList.hpp"

/* ObjectList */
template<typename T>
ObjectList<T>::~ObjectList(){
    for(int i = 0; i < list.size(); i++)
        delete list.at(i);
};

// Get
template<typename T>
vector<T> ObjectList<T>::GetList(){ return list; };

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

// Methods
vector<int> StockList::GetRandomIndexes(int start, int end, int size){

    vector<int> v;
    vector<int> result;
    int random;
    int count = 0;
    bool isRepeated = false; // First number will always non-repeated

    // Configure range_list
    for(int i = start; i < end; i++){
        v.push_back(i);
    }

    // Need Enhancement //
    while(count != size){
        random = GenerateRandomWithRange(start, end);
        isRepeated = CheckRedundance(v, random);

        // if random number repeated, then get another until it is not.
        while(isRepeated){
            random = GenerateRandomWithRange(start, end);
            isRepeated = CheckRedundance(v, random);
        }

        // Then push it to result
        result.push_back(random);

        // Reset values
        isRepeated = true;
        count ++;
    }
    return result;
};

bool StockList::CheckRedundance(vector<int>& v, int random){

    // If the element found in the range_list, it means it is not used yet.
    if (find(v.begin(), v.end(), random) != v.end()){

        // Pop out the element and break while loop
        remove(v.begin(), v.end(), random);
        v.pop_back();
        return false;
    }
    // Otherwise, the number has been used. So return true and pick another one.
    else{
        //cout << random << " Has been repeated" << endl;
        return true;
    }
};

int StockList::GenerateRandomWithRange(int start, int end){
    return start + (rand()%(end - start + 1));
};

vector<Stock*> StockList::GenerateStocks(string filePath, int numberOfStocks){
    string symbol, name, type;
    double stockPrice = 0;
    vector<Stock*> result;
    vector<tuple<string, string, string>> data;

    // Get random number vector
    vector<int> v = GetRandomIndexes(1, 500, numberOfStocks);

    // Extract whole data from csv file
    data = this->ExtractData(filePath);

    for(int i = 0; i < v.size(); i++){

        // Get random number from the number vector
        int INDEX = v.at(i);

        // Create Company Object
        name = get<1>(data.at(INDEX));
        type = get<2>(data.at(INDEX));
        Company* c = new Company(name, type);

        // Create Stocks Object
        symbol = get<0>(data.at(INDEX));
        Stock* s = new Stock(symbol, stockPrice, c);

        // Add to vector
        list.push_back(s);
    }

    // Delete extracted data
    data.clear();
    return result;
};
