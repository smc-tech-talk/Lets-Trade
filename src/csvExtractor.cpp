#include "csvExtractor.hpp"

/* CSVExtractor */

// Constructor
CSVExtractor::CSVExtractor(string filePath){
    ifstream ip(filePath);
    this->ExtractData(ip);
    ip.close();
};

// Methods
vector<vector<string>> CSVExtractor::GetResult(){ return this->result; };

void CSVExtractor::ExtractData(ifstream& ip){
    vector<vector<string>> result;
    vector<string> v;
    string symbol, name, type;

    if(!ip.is_open()) cout << "ERROR" << endl;
    else
    {
        while(ip.good()){
            this->ExtractOneLine(ip, symbol, name, type);
            v.push_back(symbol); v.push_back(name); v.push_back(type);
            result.push_back(v);
            v.clear();
        }
    }
    this->result = result;
};

void CSVExtractor::ExtractOneLine(ifstream& ip, string& s, string& n, string& t){
    getline(ip, s, ',');
    getline(ip, n, ',');
    getline(ip, t, '\n');
};

/* GenerateRandomNumbers */

// Constructor
GenerateRandomNumbers::GenerateRandomNumbers(int start, int end, int size){

    vector<int> v;
    vector<int> result;
    int random;
    int count = 0;

    for(int i = start;  i <= end; i++) //0 - 9
        v.push_back(i);

    while(count != size){
        random = this->GenerateRandomWithRange(start, end);

        // If the vector element in the index is -1, pick again
        while(v.at(random) == -1)
            random = this->GenerateRandomWithRange(start, end);
        result.push_back(v.at(random));

        // Replace the used number as -1
        v.at(random) = -1;
        count ++;
    }
    v.clear();
    this->numbers = result;
};

// Methods
vector<int> GenerateRandomNumbers::GetNumbers()
    { return this->numbers; };
int GenerateRandomNumbers::GenerateRandomWithRange(int start, int end)
    { return start + (rand()%(end - start)); };
