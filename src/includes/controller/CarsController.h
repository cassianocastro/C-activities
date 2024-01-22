#ifndef FROTA_H

#define FROTA_H

#include <iso646.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../model/CarModel.h"
#include "../view/CarsView.h"

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

extern Car frota[];

extern const unsigned int ARRAY_SIZE;

/**
 *
 */
void start(void);

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

#endif