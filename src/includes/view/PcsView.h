#ifndef PCS_VIEW_H

#define PCS_VIEW_H

#include <iso646.h>
#include <stdio.h>

#include "../model/Pc.h"

/**
 *
 */
void showComputerForm(Computer* const);

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