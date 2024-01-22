#ifndef PCS_VIEW_H

#define PCS_VIEW_H

#include "../model/Pcs.h"

/**
 *
 */
void showComputerForm(byte);

/**
 *
 */
void printComputerInfo(byte, const Computer* const);

/**
 *
 */
const unsigned int getMainMenuChoice(void);

/**
 *
 */
const unsigned int getUpdateMenuChoice(void);

/**
 *
 */
const byte getComputerID(void);

#endif