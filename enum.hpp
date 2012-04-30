#ifndef ENUM_H
#define ENUM_H

//This class is purely for sharing enums between classes.

//Current calculator mode that the user is in.
enum MAIN_MODE
{
    MENU,
    SCI_CALC,
    EQ_COMPONENT,
    DIVIDER,
    EXIT
};

//Modes that make up a MODE.  Put all sub-modes here, 
//no matter which mode your in.
enum SUB_MODE
{
    NONE,
    RESISTANCE,
    CAPACITANCE,
    INDUCTANCE,
    
    CURRENT,
    VOLTAGE
};

#endif
