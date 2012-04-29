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
void submenu(MODE& currentMode, SUB_MODE& currentSubMode);
void sci_calculator(SciCalcParser& calcParse, MODE& currentMode);
void equivalent_component(EquivResParser& resistParser, MODE& currentMode, SUB_MODE& currentSubMode);

int main()
{
    MODE currentMode = MENU;
    SUB_MODE currentSubMode = RESISTANCE;
    SciCalcParser calcParser;
    EquivResParser resistanceParser;

    while (currentMode != EXIT)
    {
        switch (currentMode)
        {
            case MENU:
                menu(currentMode, currentSubMode);
                break;
            case SCI_CALC:
                sci_calculator(calcParser, currentMode);
                break;
            case EQ_COMPONENT:
                equivalent_component(resistanceParser, currentMode, currentSubMode);
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
			submenu(currentMode, currentSubMode);
                        if (currentSubMode != NONE)
                                cout << "Enter an expression to calculate or type \"exit\" to return to the menu." << endl;
			break;
		}
        default:
            cout << "Error: Invalid choice\n" << endl;
    }
}

void submenu(MODE& currentMode, SUB_MODE& currentSubMode)
{
	string subChoice; // using string instead of int to prevent whitespace issues with other parts of the program
    cout << "What would you like to find the equivalence of?." <<  endl
	    << "1. Resistance" << endl
	    << "2. Capacitance" << endl
	    << "3. Inductance" << endl
        << "9. Help" << endl
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
        case 9:
            currentSubMode = NONE;
            cout << Help::getHelp(currentMode, currentSubMode);
            break;
        default:
	        currentSubMode = NONE;
    }
}

void sci_calculator(SciCalcParser& calcParser, MODE& currentMode)
{
    string exp;
    getline(cin, exp);
    
    if (exp.find("exit") == string::npos && exp.find("EXIT") == string::npos)
    {
        calcParser.setExpression(exp);
        //cout << calcParser.convertToPostfix(exp) << endl;
        cout << calcParser.evaluateExpression() << endl;
    }
    else
    {
        cout << endl;
        currentMode = MENU;
    }
}

void equivalent_component(EquivResParser& resistanceParser, MODE& currentMode, SUB_MODE& currentSubMode)
{
    //Depending on the sub mode, perform calculations.  Can't remember how to do this.
    string exp;
    getline(cin, exp);
      
    if (exp.find("exit") == string::npos && exp.find("EXIT") == string::npos)
    {
        resistanceParser.setExpression(exp);
        cout << resistanceParser.evaluateExpression();
        switch (currentSubMode)
        {
            case RESISTANCE:
                cout << " ohms"  << endl;
                break;
            case CAPACITANCE:
                cout << " F"  << endl;
                break;
            case INDUCTANCE:
                cout << " H" << endl;
                break;
        }
    }
    else
    {
        cout << endl;
        currentMode = MENU;
    } 
}
