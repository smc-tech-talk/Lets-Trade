#include "csvExtractor.hpp"

CSVExtractor::CSVExtractor(string filePath){
    ifstream ip(filePath);
    this->ExtractData(ip);
    ip.close();
};

void CSVExtractor::ExtractData(ifstream& ip){
    if(!ip.is_open())
        cout << "ERROR" << endl;

    string symbol;
    string name;
    string type;

    while(ip.good()){
        data = this->ExtractOneLine(ip, symbol, name, type);
        cout << "Symbol:\t" << symbol << endl;
        cout << "Name:\t" << name << endl;
        cout << "Type:\t" << type << endl;

    }

};

void CSVExtractor::ExtractOneLine(ifstream& ip, string& s, string& n, string& t){
    getline(ip, s, ',');
    getline(ip, n, ',');
    getline(ip, t, '\n');
};
