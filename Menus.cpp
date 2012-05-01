#include <iostream>
#include <string>
#include "Menus.hpp"
#include "enum.hpp"
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
	        /* TODO: Design formula sheets with three submenu choices:
                    -common constants
                    -Ohm's Law, voltage/current division, power, other common ECE formulas
                    -Basic op-amp circuits (summing, difference, inverting, differential, integrating, etc.) formulas
            */
	        break;
	    case '9':
            Help::getHelp();
            break;
        case '0':
            currentModes.mainMode = OPTION;
            currentModes.subMode = NONE;
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
            currentModes.subMode = NONE;
            break;
    }
}

void prefixMenu()
{
    cout << "   1. Tera [T] (10^12)" << endl;
    cout << "   2. Giga [G] (10^9)" << endl;
    cout << "   3. Mega [M] (10^6)" << endl;
    cout << "   4. kilo [k] (10^3)" << endl;
    cout << "   5. base (10^0)" << endl;
    cout << "   6. milli [m] (10^-3)" << endl;
    cout << "   7. micro [u] (10^-6)" << endl;
    cout << "   8. nano [n] (10^-9)" << endl;
    cout << "   9. pico [p] (10^-12)" << endl;
    cout << "   0. Main Menu" << endl;
}

