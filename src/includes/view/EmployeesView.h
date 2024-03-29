#ifndef EMPLOYEES_VIEW_H

#define EMPLOYEES_VIEW_H

#include <stdbool.h>
#include <iso646.h>

#include "../pip.h"
#include "../model/Employee.h"

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