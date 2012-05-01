#include <iostream>
#include <fstream>
#include <string>
#include "Formulas.hpp"

using std::cout;
using std::ifstream;
using std::string;
using std::endl;

void printFormulas()
{
    ifstream in("formulas.txt");
    
    string line;
    getline(in, line);
    
    while (in)
    {
        cout << line << endl;
        getline(in, line);
    }
}
