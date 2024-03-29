#ifndef PIP_H

#define PIP_H

#include <ctype.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

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
int generateEvenNumber(const int);

/**
 *
 */
int generateOddNumber(const int);

/**
 *
 */
int generatePrimeNumber(const int);

/**
 *
 */
char verifyResponse(char);

/**
 *
 */
bool isValid(int, int, int);

/**
 *
 */
const char* getMonthName(byte);

#endif