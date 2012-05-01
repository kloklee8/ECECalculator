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
} formulaLists;

string readCategory(ifstream& file, string category)
{
    string startDelimter = "<start of ";
    string endDelimiter = "<end of";
    string formulas = "";
    bool reading = false;
    string line;
    getline(file, line);
    
    while (file)
    {
        if (reading)
        {
            formulas += line;
        }
        else if (line.find(startDelimter + category) != string::npos)
        {
            reading = true;
        }
        else if (line.find(endDelimiter + category) != string::npos)
        {
            reading = false;
            break;
        }
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
}

void printFormulas()
{
    cout << formulaLists.general + formulaLists.thevenin + formulaLists.cap_ind + formulaLists.rlc_circuits;
}
