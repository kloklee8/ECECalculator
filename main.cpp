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
#include "Divider.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

struct MODES
{
    MAIN_MODE mainMode;
    SUB_MODE subMode;
} currentModes;

void menu();
void eqComponentSubmenu();
void dividerSubmenu();
void sci_calculator(SciCalcParser& calcParse);
void equivalent_component(EquivResParser& resistParser);
void divider();

int main()
{
    currentModes.mainMode = MENU;
    currentModes.subMode = NONE;
    SciCalcParser calcParser;
    EquivResParser resistanceParser;

    while (currentModes.mainMode != EXIT)
    {
        switch (currentModes.mainMode)
        {
            case MENU:
                menu();
                break;
            case SCI_CALC:
                sci_calculator(calcParser);
                break;
            case EQ_COMPONENT:
                equivalent_component(resistanceParser);
                break;
            case DIVIDER:
                divider();
                break;
            case EXIT:
                break;
        }
    }
        
    return 0;
}


void menu()
{
    string choice; // using string instead of int to prevent whitespace issues with other parts of the program
    cout << "1. Scientific Calculator" << endl <<
            "2. Circuit Component Equivalence" << endl <<
            "3. Current and Voltage Dividers" << endl <<
            "9. Help" << endl <<
            "0. Exit" << endl;
    getline(cin, choice);

    switch (choice[0] - '0')
    {
        case 9:
            cout << Help::getHelp(currentModes.mainMode, currentModes.subMode);
            break;
        case 0:
            currentModes.mainMode = EXIT;
            break;
        case 1: 
            currentModes.mainMode = SCI_CALC;
            cout << "Enter an expression to calculate or type \"exit\" to return to the menu." << endl;
            break;
        case 2:
			currentModes.mainMode = EQ_COMPONENT;
			eqComponentSubmenu();
			break;
		case 3:
	        currentModes.mainMode = DIVIDER;
	        dividerSubmenu();
	        break;
        default:
            cout << "Error: Invalid choice\n" << endl;
    }
}

void eqComponentSubmenu()
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
	        currentModes.subMode = RESISTANCE;
	        break;
        case 2:
	        currentModes.subMode = CAPACITANCE;
	        break;
        case 3:
	        currentModes.subMode = INDUCTANCE;
	        break;
        case 9:
            currentModes.subMode = NONE;
            cout << Help::getHelp(currentModes.mainMode, currentModes.subMode);
            return;
        default:
	        currentModes.subMode = NONE;
    }
    cout << "Enter an expression to calculate or type \"exit\" to return to the menu." << endl;
}

void dividerSubmenu()
{
    string subChoice;
    cout << "What would you like to divide?" << endl
         << "1. Current through parallel resistors" << endl
         << "2. Voltage across resistors in series" << endl
         << "0. Exit" << endl;
    getline(cin,subChoice);
    
    switch(subChoice[0] - '0')
    {
        case 1:
            currentModes.subMode = CURRENT;
            break;
        case 2:
            currentModes.subMode = VOLTAGE;
            break;
        default:
            currentModes.subMode = NONE;
            break;
    }
}

void sci_calculator(SciCalcParser& calcParser)
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
        currentModes.mainMode = MENU;
    }
}

void equivalent_component(EquivResParser& resistanceParser)
{
    if (currentModes.subMode == NONE)
    {
        eqComponentSubmenu();
        return;
    }
    //Depending on the sub mode, perform calculations.
    string exp;
    getline(cin, exp);
      
    if (exp.find("exit") == string::npos && exp.find("EXIT") == string::npos)
    {
        resistanceParser.setExpression(exp);
        cout << resistanceParser.evaluateExpression();
        switch (currentModes.subMode)
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
        currentModes.mainMode = MENU;
    } 
}

void divider()
{
    cout << "Enter the value of the source or type \"exit\" to return to the menu." << endl;
    string exp;
    getline(cin, exp);
    

    if (exp.find("exit") == string::npos && exp.find("EXIT") == string::npos)
    {
        Divider divider;
        double sourceVal, r1, r2;
        
        sourceVal = strtod(exp.c_str(), NULL);

        cout << "Enter the value of the first resistor" << endl;
        getline(cin, exp);

        r1 = strtod(exp.c_str(), NULL);

        cout << "Enter the value of the second resistor" << endl;
        getline(cin,exp);

        r2 = strtod(exp.c_str(), NULL);

        double result1, result2;

        if (currentModes.subMode == CURRENT)
        {
            divider.divideCurrent(sourceVal, r1, r2, &result1, &result2);
            cout << "The current through the first resistor is " << result1 << " amps." << endl
                 << "The current through the second resistor is " << result2 << " amps." << endl;
        }
        else
        {
            divider.divideVoltage(sourceVal, r1, r2, &result1, &result2);
            cout << "The voltage across the first resistor is " << result1 << " volts." <<endl
                 << "The voltage across the second resistor is " << result2 << " volts." <<endl;
        }

    }
    else
    {
        currentModes.mainMode = MENU;
    }
}
