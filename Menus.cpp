#include <iostream>
#include <string>
#include "Menus.hpp"
#include "Help.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

extern MODES currentModes;
extern OPTIONS currentOptions;

void menu()
{
    string choice; // using string instead of int to prevent whitespace issues with other parts of the program
    cout << "1. Scientific Calculator" << endl
         << "2. Circuit Component Equivalence" << endl
         << "3. Current and Voltage Dividers" << endl
         << "4. Convert Between Unit Prefixes" << endl
         << "5. Formulas" << endl
         << "9. Help" << endl
         << "0. Options" << endl
         << "q. Quit" << endl;
    getline(cin, choice);

    switch (choice[0])
    {
        
        case '1': 
            currentModes.mainMode = SCI_CALC;
            currentModes.subMode = NONE;
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
	        currentModes.mainMode = CONVERSION;
	        currentModes.subMode = NONE;
	        prefixMenu();
	        break;
	    case '5':
	        currentModes.mainMode = FORMULA;
	        currentModes.subMode = NONE;
	        break;
	    case '9':
            getHelp();
            break;
        case '0':
            currentModes.mainMode = OPTION;
            currentModes.subMode = NONE;
            break;
        case 'q':
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
            currentModes.subMode = VOLTAGE;
            break;
    }
}

void prefixMenu()
{
    cout << "   1. Tera [T] (10^12)" << endl
         << "   2. Giga [G] (10^9)" << endl
         << "   3. Mega [M] (10^6)" << endl
         << "   4. kilo [k] (10^3)" << endl
         << "   5. base (10^0)" << endl
         << "   6. milli [m] (10^-3)" << endl
         << "   7. micro [u] (10^-6)" << endl
         << "   8. nano [n] (10^-9)" << endl
         << "   9. pico [p] (10^-12)" << endl
         << "   0. Main Menu" << endl;
}

void helpEqComponentSubMenu(MAIN_MODE& helpMode, SUB_MODE& helpSubMode)
{
    cout << "\n\nEquivalent Component help:" << endl
         << "   This mode is used to determine the equivalence of multiple circuit components" << endl
         << "   that are in series or parallel.  For example, you may want to know the " << endl
         << "   equivalence of five resistors that are in a complex network." << endl
         << "   Operators include \'+\' for series and \'|\' for parallel." << endl;
    cout << "       1. Resistance\n       2. Capacitance\n       3. Inductance\n       0. Return to Main menu\n";
    string choice;
    getline(cin, choice);
    switch(choice[0] - '0')
    {
        case 1:
            helpSubMode = RESISTANCE;
            break;
        case 2:
            helpSubMode = CAPACITANCE;
            break;
        case 3:
            helpSubMode = INDUCTANCE;
            break;
        case 0:
            helpMode = MENU;
            helpSubMode = NONE;
            break;
    }
    
    
    
}

void helpMainMenu(MAIN_MODE& helpMode)
{
    cout << ("1. Scientific Calculator\n2. Equivalent Component\n3. Voltage and "
            "Current dividers\n4. Prefix Conversions\n5. Formula Sheet\n6. Options\n"
            "7. Command line arguments\n0. Exit \"Help\"\n");
    string choice;
    getline(cin, choice);
    switch(choice[0] - '0')
    {
        case 1:
            helpMode = SCI_CALC;
            break;
        case 2:
            helpMode = EQ_COMPONENT;
            break;
        case 3:
            helpMode = DIVIDER;
            break;
        case 4:
            helpMode = CONVERSION;
            break;
        case 5:
            helpMode = FORMULA;
            break;
        case 6:
            helpMode = OPTION;
            break;
        case 7:
            helpMode = HELP;
            break;
        case 0:
            helpMode = EXIT;
    }    
}

int formulaMenu()
{
    cout << "Select a category of formulas:" << endl
         << "1. Basic Circuit Laws" << endl
         << "2. Thevenin and Norton Equivalent Circuits" << endl
         << "3. Capacitors and Inductors" << endl
         << "4. RLC Circuits" << endl
         << "5. AC Circuits" << endl
         << "6. Op Amps" << endl
         << "7. All" << endl
         << "0. Main Menu" << endl;
    string choice;
    getline(cin, choice);
    
    if (choice[0] == '0')
    {
        currentModes.mainMode = MENU;
        return 0;
    }
    
    if (choice[0] < '0' || choice[0] > '7')
    {
        return -1;
    }
    
    return (choice[0] - '0');
}

void waitForUser()
{
    cout << "Enter any key to continue. ";
    string garbage;
    getline(cin, garbage);
}

