#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include <fstream>
#include <iostream> 
//#include <sstream>
#include <vector>

class CSVExtractor{
public:
    CSVExtractor(string);
    void ExtractData(ifstream&);
    void ExtractOneLine(ifstream&, string&, string&, string&);
};

#endif
