#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include "ExpressionParser.hpp"
#include "SciCalcParser.hpp"
#include "EquivResParser.hpp"
#include "EquivCapParser.hpp"
#include "EquivIndParser.hpp"
#include "enum.hpp"
#include "Help.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

void menu(MODE& currentMode, SUB_MODE& currentSubMode);
void submenu(SUB_MODE& currentSubMode);
void sci_calculator(MODE& currentMode);
void equivalent_component(MODE& currentMode);

int main()
{
    MODE currentMode = MENU;
    SUB_MODE currentSubMode = RESISTANCE;

    while (currentMode != EXIT)
    {
        switch (currentMode)
        {
            case MENU:
                menu(currentMode, currentSubMode);
                break;
            case SCI_CALC:
                sci_calculator(currentMode);
                break;
            case EQ_COMPONENT:
                equivalent_component(currentMode);
                break;
            case EXIT:
                break;
        }
    }
        
    return 0;
}


void menu(MODE& currentMode, SUB_MODE& currentSubMode)
{
    string choice; // using string instead of int to prevent whitespace issues with other parts of the program
    cout << "1. Scientific Calculator" << endl <<
            "2. Circuit Component Equivalence" << endl <<
            "9. Help" << endl <<
            "0. Exit" << endl;
    getline(cin, choice);

    switch (choice[0] - '0')
    {
        case 9:
            cout << Help::getHelp(currentMode, currentSubMode);
            break;
        case 0:
            currentMode = EXIT;
            break;
        case 1: 
            currentMode = SCI_CALC;
            cout << "Enter an expression to calculate or type \"exit\" to return to the menu." << endl;
            break;
        case 2:
		{
			currentMode = EQ_COMPONENT;
			submenu(currentSubMode);
	        cout << "Enter an expression to calculate or type \"exit\" to return to the menu." << endl;
			break;
		}
        default:
            cout << "Error: Invalid choice\n" << endl;
    }
}

void submenu(SUB_MODE& currentSubMode)
{
	string subChoice; // using string instead of int to prevent whitespace issues with other parts of the program
    cout << "What would you like to find the equivalence of?." <<  endl
	    << "1. Resistance" << endl
	    << "2. Capacitance" << endl
	    << "3. Inductance" << endl
	    << "0. Exit" << endl;
    getline(cin, subChoice);
    switch(subChoice[0] - '0')
    {
        case 1:
	        currentSubMode = RESISTANCE;
	        break;
        case 2:
	        currentSubMode = CAPACITANCE;
	        break;
        case 3:
	        currentSubMode = INDUCTANCE;
	        break;
        default:
	        currentSubMode = NONE;
    }
}

void sci_calculator(MODE& currentMode)
{
    string exp;
    getline(cin, exp);
    
    SciCalcParser calcParser(exp);

    if (exp.find("exit") == string::npos && exp.find("EXIT") == string::npos)
    {
        //cout << calcParser.convertToPostfix(exp) << endl;
        calcParser.convertToPostfix();
        cout << calcParser.evaluatePostFix() << endl;
    }
    else
    {
        cout << endl;
        currentMode = MENU;
    }
}

void equivalent_component(MODE& currentMode)
{
    //Depending on the sub mode, perform calculations.  Can't remember how to do this.
	
	string exp;
    getline(cin, exp);
    
    EquivResParser resistanceParser(exp);

    if (exp.find("exit") == string::npos && exp.find("EXIT") == string::npos)
    {
        resistanceParser.convertToPostfix();
        cout << resistanceParser.evaluatePostFix() << "ohms" << endl;
    }
    else
    {
        cout << endl;
        currentMode = MENU;
    } 
}
