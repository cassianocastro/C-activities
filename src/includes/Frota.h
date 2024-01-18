#ifndef FROTA_H

#define FROTA_H

#include <iso646.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 20

typedef unsigned char byte;

/**
 *
 */
typedef enum
{
    EXIT,
    CREATE,
    READ,
    DELETE
}
Options;

/**
 *
 */
typedef struct
{
	char model[STRING_SIZE];
	char mark[STRING_SIZE];
	char placa[STRING_SIZE];
	char color[STRING_SIZE];

	unsigned short release;
}
Car;

extern Car frota[];

extern const unsigned int ARRAY_SIZE;

/**
 *
 */
Car createCar(void);

/**
 *
 */
void addCar(void);

/**
 *
 */
void showCars(void);

/**
 *
 */
void deleteCar(void);

/**
 *
 */
void showCarForm(Car* const);

/**
 *
 */
void printCarInfo(const Car* const);

/**
 *
 */
const unsigned int showMainMenu(void);

/**
 *
 */
void start(void);

#endif