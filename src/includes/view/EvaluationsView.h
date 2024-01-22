#ifndef EVALUATION_VIEW_H

#define EVALUATION_VIEW_H

#include <iso646.h>
#include <stdbool.h>
#include <stdio.h>

#include "../model/EvaluationModel.h"

/**
 *
 */
void showComputerForm(unsigned short int);

/**
 *
 */
void printComputer(const Computer* const);

/**
 *
 */
unsigned int getComputerID(void);

/**
 *
 */
const unsigned int getMainMenuChoice(void);

/**
 *
 */
const unsigned int getUpdateMenuChoice(void);

#endif