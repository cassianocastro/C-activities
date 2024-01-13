#ifndef EMPLOYEES_H

#define EMPLOYEES_H

#include <inttypes.h>
#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./PIP.h"

#define ARRAY_SIZE 10
#define SIZE 50
#define MONTHS 12

typedef unsigned char byte;

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

/**
 *
 */
typedef struct
{
	int day;
    int month;
    int year;
}
BirthDate;

/**
 *
 */
typedef struct
{
	char cpf[14];
	char name[SIZE];
	char address[SIZE];

	float wage[MONTHS];
    float sum;
	int code;

	BirthDate bd;
}
Employee;

extern Employee employees[];

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
Employee createEmployee(void);

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