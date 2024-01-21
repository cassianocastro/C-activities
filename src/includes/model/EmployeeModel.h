#ifndef EMPLOYEES_MODEL_H

#define EMPLOYEES_MODEL_H

#define SIZE 50
#define MONTHS 12

typedef unsigned char byte;

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

/**
 *
 */
Employee createEmployee(void);

#endif