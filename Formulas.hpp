#ifndef FORMULAS_H
#define FORMULAS_H

#include <fstream>
#include <string>
using std::string;
using std::ifstream;
void readFormulas();
void printFormulas();
string readCategory(ifstream& file, string category);

#endif
