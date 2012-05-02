#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include "PrefixConverter.hpp"
#include "enum.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

// extern because declared in main. In order to keep main short, this set of
// code, which all perform prefix conversion tasks, was moved into its own files,
// but still needs access to the current program's modes and options.
extern MODES currentModes;
extern OPTIONS currentOptions;

double convertFromTo(int convertFrom, int convertTo, double fromValue)
{
    int exponent = -3 * (convertFrom - convertTo);
    return fromValue * pow(10, exponent);
}

void printPrefix(int unit)
{
    switch (unit)
    {
        case 1:
            cout << "Tera [T]";
            break;
        case 2:
            cout << "Giga [G]";
            break;
        case 3:
            cout << "Mega [M]";
            break;
        case 4:
            cout << "kilo [k]";
            break;
        case 5:
            cout << "base";
            break;
        case 6:
            cout << "milli [m]";
            break;
        case 7:
            cout << "micro [u]";
            break;
        case 8:
            cout << "nano [n]";
            break;
        case 9:
            cout << "pico [p]";
            break;
        default:
            cout << "invalid units";
    }
}

void printConversion(int convertFrom, int convertTo, double fromValue, double convertedValue)
{
    cout << fromValue << " ";
    printPrefix(convertFrom);
    cout << " = " << convertedValue << " ";
    printPrefix(convertTo);
    cout << endl;
}

void convertPrefixes()
{
    cout << "Convert from: ";
    
    string choice;
    getline(cin, choice);
    
    if (choice[0] == '0')
    {
        currentModes.mainMode = MENU;
        currentModes.subMode = NONE;
        return;
    }
    else if (choice.size() > 1 || choice[0] < '1' || choice[0] > '9')
    {
        cout << "Invalid choice." << endl;
        return;
    }
    
    int convertFrom = choice[0] - '0';
    
    cout << "Convert to: ";
    getline(cin, choice);
    
    if (choice[0] == '0')
    {
        currentModes.mainMode = MENU;
        currentModes.subMode = NONE;
        return;
    }
    else if (choice.size() > 1 || choice[0] < '1' || choice[0] > '9')
    {
        cout << "Invalid choice." << endl;
        return;
    }
    
    int convertTo = choice[0] - '0';
    
    cout << "Value to convert: ";
    string fromValueStr;
    getline(cin, fromValueStr);
    double fromValue = atof(fromValueStr.c_str());
    
    double convertedValue = convertFromTo(convertFrom, convertTo, fromValue);
    
    printConversion(convertFrom, convertTo, fromValue, convertedValue);
}
