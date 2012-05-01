#ifndef MENUS_H
#define MENUS_H

#include "enum.hpp"
        
void menu();
void eqComponentSubmenu();
void dividerSubmenu();
void prefixMenu();
void waitForUser();
void helpEqComponentSubMenu(MAIN_MODE& helpMode, SUB_MODE& helpSubMode);
void helpMainMenu(MAIN_MODE& helpMode, SUB_MODE& helpSubMode);
#endif
