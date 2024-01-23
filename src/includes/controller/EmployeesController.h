#ifndef EMPLOYEES_CONTROLLER_H

#define EMPLOYEES_CONTROLLER_H

#include <inttypes.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../model/Employee.h"
#include "../view/EmployeesView.h"

#define ARRAY_SIZE 10

/**
 *
 */
typedef enum
{
    EXIT,
    CREATE,
    READ,
    DELETE,
    VALUES
}
Options;

extern Employee employees[];

/**
 *
 */
void start(void);

/**
 *
 */
void addEmployee(void);

/**
 *
 */
void showEmployees(void);

/**
 *
 */
void removeEmployee(void);

/**
 *
 */
void wages(void);

/**
 *
 */
void insertAllWages(int);

/**
 *
 */
void insertWage(int);

#endif