#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include "ExpressionParser.hpp"
#include "SciCalcParser.hpp"
#include "EquivComponentParser.hpp"
#include "enum.hpp"
#include "Help.hpp"
#include "Divider.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::fixed;
using std::setprecision;

struct MODES
{
    MAIN_MODE mainMode;
    SUB_MODE subMode;
} currentModes;

struct OPTIONS
{
    ANGLE angleMode; // TODO: Implement angle changes
    // if true, display help on entrance to each mode. If false, only display help at beginning of program.
    bool helpDisplay; // TODO: Implement help toggling
    int precision;
} currentOptions;

void menu();
void eqComponentSubmenu();
void dividerSubmenu();
void sci_calculator(SciCalcParser& calcParse);
void equivalent_component(EquivComponentParser& eqComponentParser);
void divider();
void options(SciCalcParser& calcParser);

int main()
{
    currentModes.mainMode = MENU;
    currentModes.subMode = NONE;
    
    currentOptions.angleMode = RADIAN;
    currentOptions.helpDisplay = true;
    currentOptions.precision = 5;
    cout << fixed << setprecision(5);
    
    SciCalcParser calcParser;
    EquivComponentParser eqComponentParser;

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
                equivalent_component(eqComponentParser);
                break;
            case DIVIDER:
                divider();
                break;
            case CONVERSION:
                break;
            case FORMULA:
                break;
            case OPTION:
                options(calcParser);
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
    cout << "1. Scientific Calculator" << endl
         << "2. Circuit Component Equivalence" << endl
         << "3. Current and Voltage Dividers" << endl
         << "4. Convert Between Units" << endl
         << "5. Formulas" << endl
         << "9. Help" << endl
         << "0. Options" << endl
         << "e. Exit" << endl;
    getline(cin, choice);

    switch (choice[0])
    {
        
        case '1': 
            currentModes.mainMode = SCI_CALC;
            cout << "Enter an expression to calculate. Enter \"m\" or \"q\" to return to the main menu or quit." << endl;
            break;
        case '2':
			currentModes.mainMode = EQ_COMPONENT;
			eqComponentSubmenu();
			break;
		case '3':
	        currentModes.mainMode = DIVIDER;
	        dividerSubmenu();
	        break;
	    case '4':
	        // TODO: Implement conversions, with prefixes/units as submenu choices.
	        break;
	    case '5':
	        /* TODO: Design formula sheets with three submenu choices:
                    -common constants
                    -Ohm's Law, voltage/current division, power, other common ECE formulas
                    -Basic op-amp circuits (summing, difference, inverting, differential, integrating, etc.) formulas
            */
	        break;
	    case '9':
            cout << Help::getHelp(currentModes.mainMode, currentModes.subMode);
            break;
        case '0':
            currentModes.mainMode = OPTION;
            break;
        case 'e':
            currentModes.mainMode = EXIT;
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
	    << "0. Main Menu" << endl;
    getline(cin, subChoice);
    
    switch (subChoice[0])
    {
        case '1':
	        currentModes.subMode = RESISTANCE;
	        break;
        case '2':
	        currentModes.subMode = CAPACITANCE;
	        break;
        case '3':
	        currentModes.subMode = INDUCTANCE;
	        break;
        case '9':
            currentModes.subMode = NONE;
            cout << Help::getHelp(currentModes.mainMode, currentModes.subMode);
            return;
        case '0':
            currentModes.subMode = NONE;
            currentModes.mainMode = MENU;
            return;
        default:
	        currentModes.subMode = NONE;
    }
    cout << "Enter an equivalent expression to calculate. Enter \"m\" or \"q\" to return to the main menu or quit." << endl;
}

void dividerSubmenu()
{
    string subChoice;
    cout << "What would you like to divide?" << endl
         << "1. Current through parallel resistors" << endl
         << "2. Voltage across resistors in series" << endl
         << "0. Main Menu" << endl;
    getline(cin,subChoice);
       
    switch (subChoice[0])
    {
        case '1':
            currentModes.subMode = CURRENT;
            break;
        case '2':
            currentModes.subMode = VOLTAGE;
            break;
        case '0':
            currentModes.mainMode = MENU;
            currentModes.subMode = NONE;
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
    
    if (exp[0] != 'm' && exp[0] != 'q' &&
        exp.find("menu") == string::npos && exp.find("quit") == string::npos)
    {
        calcParser.setExpression(exp);
        string result = calcParser.evaluateExpression();
        cout << atof(result.c_str()) << endl;
    }
    else
    {
        cout << endl;
        
        if (exp[0] == 'm' || exp.find("menu") != string::npos)
        {
            currentModes.mainMode = MENU;
        }
        else
        {
            currentModes.mainMode = EXIT;
        }
    }
}

void equivalent_component(EquivComponentParser& eqComponentParser)
{
    if (currentModes.subMode == NONE)
    {
        eqComponentSubmenu();
        return;
    }
    
    //Depending on the sub mode, perform calculations.
    string exp;
    getline(cin, exp);
      
    if (exp[0] != 'm' && exp[0] != 'q' &&
        exp.find("menu") == string::npos && exp.find("quit") == string::npos)
    {
        eqComponentParser.setMode(currentModes.subMode);
        eqComponentParser.setExpression(exp);
        string result = eqComponentParser.evaluateExpression();
        cout << atof(result.c_str()) << endl;
        
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
        
        if (exp[0] == 'm' || exp.find("menu") != string::npos)
        {
            currentModes.mainMode = MENU;
        }
        else
        {
            currentModes.mainMode = EXIT;
        }
    } 
}

void divider()
{
    cout << "Enter the value of the source. Enter \"m\" or \"q\" to return to the main menu or quit." << endl;
    string exp;
    getline(cin, exp);

    if (exp[0] != 'm' && exp[0] != 'q' &&
        exp.find("menu") == string::npos && exp.find("quit") == string::npos)
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
        else if (currentModes.subMode == VOLTAGE)
        {
            divider.divideVoltage(sourceVal, r1, r2, &result1, &result2);
            cout << "The voltage across the first resistor is " << result1 << " volts." <<endl
                 << "The voltage across the second resistor is " << result2 << " volts." <<endl;
        }
    }
    else
    {
        cout << endl;
        
        if (exp[0] == 'm' || exp.find("menu") != string::npos)
        {
            currentModes.mainMode = MENU;
        }
        else
        {
            currentModes.mainMode = EXIT;
        }
    }
}

void options(SciCalcParser& calcParser)
{    
    string choice;
    
    do
    {
        cout << "Current Options: Enter the respective number to toggle." << endl
             << "1. Angle Units: " << ((currentOptions.angleMode == RADIAN) ? "radians" : "degrees") << endl
             << "2. Help Tips: " << ((currentOptions.helpDisplay) ? "On" : "Off") << endl
             << "3. Result Precision: " << currentOptions.precision << endl
             << "0. Main Menu" << endl;
                
        getline(cin, choice);
        
        switch (choice[0])
        {
            case '1':
                currentOptions.angleMode = ((currentOptions.angleMode == RADIAN) ? DEGREE : RADIAN);
                calcParser.setAngleMode(currentOptions.angleMode);
                break;
            case '2':
                currentOptions.helpDisplay = !(currentOptions.helpDisplay);
                break;
            case '3':
            {
                string newPrecision;
                cout << "Enter the new precision: ";
                getline(cin, newPrecision);
                int newPrec = atoi(newPrecision.c_str());
                if (newPrec <= 0 || newPrec > 15)
                {
                    cout << "Error: Precision must be between 1 and 15, inclusive." << endl;
                }
                else
                {
                    currentOptions.precision = newPrec;
                    cout << fixed << setprecision(currentOptions.precision);
                }
                break;
            }
            case '0':
                currentModes.mainMode = MENU;
                break;
        }
        
    } while (choice[0] != '0');
}
