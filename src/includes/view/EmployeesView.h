#ifndef EMPLOYEES_VIEW_H

#define EMPLOYEES_VIEW_H

#include "../model/EmployeeModel.h"

/**
 *
 */
Employee showEmployeeForm(void);

/**
 *
 */
void printEmployeeInfo(const Employee* const);

/**
 *
 */
const unsigned int getEmployeeCode(void);

/**
 *
 */
const unsigned int getMainMenuChoice(void);

#endif