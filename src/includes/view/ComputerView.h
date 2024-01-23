#ifndef COMPUTER_VIEW_H

#define COMPUTER_VIEW_H

#include <iso646.h>
#include <stdio.h>

#include "../model/Computer.h"

/**
 *
 */
Computer showComputerForm(byte);

/**
 *
 */
void printComputerInfo(const byte, const Computer* const);

/**
 *
 */
const byte getComputerID(void);

/**
 *
 */
const unsigned int getMainMenuChoice(void);

/**
 *
 */
const unsigned int getUpdateMenuChoice(void);

#endif