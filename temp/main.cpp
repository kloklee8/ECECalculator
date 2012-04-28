#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include "ExpressionParser.h"
#include "SciCalcParser.h"
#include "EquivResParser.h"
#include "EquivCapParser.h"
#include "EquivIndParser.h"

using namespace std;

enum MODE
{
    MENU,
    SCI_CALC,
	EQ_COMPONENT,
    EXIT
};

//Modes that make up a MODE.  Put all sub-modes here, no matter which mode your in.
//Temporary solution.  - Justin
enum SUB_MODE
{
    RESISTANCE,
	CAPACITANCE,
	INDUCTANCE
};

int main()
{
    MODE currentMode = MENU;
	SUB_MODE currentSubMode = RESISTANCE;

        while (currentMode != EXIT)
    {
        string choice;
        switch (currentMode)
        {
            case MENU:
            {
                cout << "1. Scientific Calculator" << endl <<
						"2. Circuit Component Equivalence" << endl <<
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
					case 2:
					{
						currentMode = EQ_COMPONENT;
						string subChoice;
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
							currentMode = MENU;
						}
						if (currentMode == EQ_COMPONENT)
							cout << "Enter an expression to calculate or type \"exit\" to return to the menu." << endl;
						break;
					}
                    default:
                        cout << "Error: Invalid choice\n" << endl;;
                }
                break;
            }
            case SCI_CALC:
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

                break;
            }
			case EQ_COMPONENT:
			{
				//Depending on the sub mode, perform calculations.  Can't remember how to do this.
				EquivResParser resistanceParser;
				string exp;
                getline(cin, exp);

                if (exp.find("exit") == string::npos && exp.find("EXIT") == string::npos)
                {
                    //cout << calcParser.convertToPostfix(exp) << endl;
                    resistanceParser.convertToPostfix(exp);
                    cout << resistanceParser.evaluatePostFix() << endl;
                }
                else
                {
                    cout << endl;
                    currentMode = MENU;
                } 
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

//string getExamples()
//{
//
//}