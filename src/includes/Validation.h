#ifndef VALIDATION_H

#define VALIDATION_H

#include <inttypes.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdio.h>

/**
 *
 */
typedef enum
{
	JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
}
Months;

/**
 *
 */
bool validadata(uint8_t, uint8_t, uint16_t);

#endif