#ifndef EVALUATION_VIEW_H

#define EVALUATION_VIEW_H

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