#include <iostream>
#include <fstream>
#include <string>
#include "Formulas.hpp"

using std::cout;
using std::ifstream;
using std::string;
using std::endl;

struct FORMULAS
{
    string general;
    string thevenin;
    string cap_ind;
    string rlc_circuits;
    string ac_circuits;
    string opAmps;
} formulaLists;

string readCategory(ifstream& file, string category)
{
    string startDelimter = "<start ";
    string endDelimiter = "<end ";
    string formulas = "";
    bool reading = false;
    
    string line;
    getline(file, line);
    
    while (file)
    {
        if (line.find(endDelimiter + category) != string::npos)
        {
            break;
        }
        else if (reading)
        {
            formulas += line + '\n';
        }
        else if (line.find(startDelimter + category) != string::npos)
        {
            reading = true;
        }
   
        getline(file, line);
    }
    return formulas;
}

void readFormulas()
{
    ifstream in("formulas.txt");
    
    formulaLists.general = readCategory(in, "general");
    formulaLists.thevenin = readCategory(in, "thevenin");
    formulaLists.cap_ind = readCategory(in, "capacitors and inductors");
    formulaLists.rlc_circuits = readCategory(in, "RLC circuits");
    formulaLists.ac_circuits = readCategory(in, "ac circuits");
    formulaLists.opAmps = readCategory(in, "op amps");
}

void printFormulas(int category)
{
    switch (category)
    {
        case 1:
            cout << formulaLists.general << endl;
            break;
        case 2:
            cout << formulaLists.thevenin << endl;
            break;
        case 3:
            cout << formulaLists.cap_ind << endl;
            break;
        case 4:
            cout << formulaLists.rlc_circuits << endl;
            break;
        case 5:
            cout << formulaLists.ac_circuits << endl;
            break;
        case 6:
            cout << formulaLists.opAmps << endl;
            break;
        default:
            cout << formulaLists.general << formulaLists.thevenin 
                 << formulaLists.cap_ind << formulaLists.rlc_circuits << 
                 << formulaLists.ac_circuits << formulaLists.opAmps << endl;
            break;
    }
    
}
