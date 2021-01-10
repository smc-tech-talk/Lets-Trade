#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include "stock.hpp"
#include <fstream>
#include <iostream>
#include <vector>

class CSVExtractor{
public:
    CSVExtractor(string);
    vector<vector<string>> GetResult();
    void ExtractData(ifstream&);
    void ExtractOneLine(ifstream&, string&, string&, string&);

private:
    vector<vector<string>> result;
};

class GenerateRandomNumbers{
public:
    GenerateRandomNumbers(int, int, int);
    vector<int> GetNumbers();
    int GenerateRandomWithRange(int, int);

private:
    vector<int> numbers;
};

#endif
