#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include "SciCalcParser.hpp"
#include "EquivComponentParser.hpp"
#include "Divider.hpp"
#include "PrefixConverter.hpp"
#include "Formulas.hpp"
#include "enum.hpp"
#include "Help.hpp"
#include "Menus.hpp"
#include "CalculationHandler.hpp"

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::scientific;
using std::string;

MODES currentModes;
OPTIONS currentOptions;

bool processCommandLineArguments(int argc, char* argv[], SciCalcParser& calcParser);

int main(int argc, char* argv[])
{
    currentModes.mainMode = MENU;
    currentModes.subMode = NONE;
    
    setOptions(RADIAN, -1, false);
    readFormulas();
    
    SciCalcParser calcParser;
    EquivComponentParser eqComponentParser;
    
    if (argc > 1)
    {
        if (!(processCommandLineArguments(argc, argv, calcParser)))
        {
            return 1;
        }
    }

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
                convertPrefixes();
                break;
            case FORMULA:
            {
                int choice = formulaMenu();
                if (choice != 0)
                {
                    printFormulas(choice);
                    waitForUser();
                }
                break;
            }
            case OPTION:
                options(calcParser);
                break;
            case EXIT:
                break;
        }
    }
    
    return 0;
}

bool processCommandLineArguments(int argc, char* argv[], SciCalcParser& calcParser)
{
    for (int i = 1; i < argc; i++)
    {
        if (string(argv[i]) == "--degrees" || string(argv[i]) == "-d")
        {
            currentOptions.angleMode = DEGREE;
            calcParser.setAngleMode(currentOptions.angleMode);
        }
        else if (string(argv[i]) == "--precision" || string(argv[i]) == "-p")
        {
            i++;
            if (i == argc)
            {
                cout << "Error: Must specify precision after --precision or -p";
                return false;
            }
            int prec = atoi(argv[i]);
            if (prec < 0 || prec > 15)
            {
                cout << "Error: Precision must be between 0 and 15, inclusive." << endl;
                return false;
            }
            else
            {
                currentOptions.precision = prec;
                if (!currentOptions.scientificNotation)
                {
                    cout << fixed;
                }
                cout << setprecision(currentOptions.precision);
            }
        }
        else if (string(argv[i]) == "--scientific" || string(argv[i]) == "-s")
        {
            currentOptions.scientificNotation = true;
            cout << scientific << setprecision(currentOptions.precision);
        }
        else if (string(argv[i]) == "--help" || string(argv[i]) == "-h")
        {
            getHelp();
        }
        else
        {
            cout << "Error: Invalid command line arguments" << endl;
            return false;
        }
    }
    return true;
}
