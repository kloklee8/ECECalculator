#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include "ExpressionParser.hpp"
#include "SciCalcParser.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

enum MODE
{
    MENU,
    SCI_CALC,
    EXIT
} currentMode;

void menu();
void sci_calculator();

int main()
{
    currentMode = MENU;

    while (currentMode != EXIT)
    {
        switch (currentMode)
        {
            case MENU:
            {
                menu();
                break;
            }
            case SCI_CALC:
            {
                sci_calculator();
                break;
            }
            case EXIT:
            {
                break;
            }
        }
    }
        
    return 0;
}

void menu()
{
    string choice; // using string instead of int to prevent whitespace issues with other parts of the program
    cout << "1. Scientific Calculator" << endl <<
            "-1. Help" << endl <<
            "0. Exit" << endl;
    getline(cin, choice);

    switch (choice[0] - '0')
    {
        case -1:
            break;
        case 0:
            currentMode = EXIT;
            break;
        case 1: 
            currentMode = SCI_CALC;
            cout << "Enter an expression to calculate or type \"exit\" to return to the menu." << endl;
            break;
        default:
            cout << "Error: Invalid choice\n" << endl;
    }
}

void sci_calculator()
{
    SciCalcParser calcParser;

    string exp;
    getline(cin, exp);

    if (exp.find("exit") == string::npos && exp.find("EXIT") == string::npos)
    {
        //cout << calcParser.convertToPostfix(exp) << endl;
        calcParser.convertToPostfix(exp);
        cout << calcParser.evaluatePostFix() << endl;
    }
    else
    {
        cout << endl;
        currentMode = MENU;
    }
}
