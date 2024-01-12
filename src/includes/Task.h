#ifndef TASK_H

#define TASK_H

#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 *
 */
typedef enum
{
    EXIT,
	ASCENDING,
    DESCENDING
}
Options;

extern const unsigned char VECTOR_SIZE, RANDOM_LIMIT;

/**
 *
 */
void printVector(int*);

/**
 *
 */
void ascendingOrder(int*);

/**
 *
 */
void descendingOrder(int*);

/**
 *
 */
void fillVectorWithRandomNumbers(int*);

/**
 *
 */
const unsigned int getMainMenuChoice(void);

/**
 *
 */
void start(void);

#endif