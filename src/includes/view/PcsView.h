#ifndef PCS_VIEW_H

#define PCS_VIEW_H

#include <iso646.h>
#include <stdio.h>

#include "../model/Pc.h"

/**
 *
 */
void clearScreen(void);

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
void showComputerForm(Computer* const);

/**
 *
 */
const byte getComputerID(void);

/**
 *
 */
void getComputerMark(char* const);

/**
 *
 */
void getComputerModel(char* const);

/**
 *
 */
void getComputerProcessor(char* const);

/**
 *
 */
unsigned int getComputerMemory(void);

/**
 *
 */
unsigned int getComputerStorage(void);

/**
 *
 */
char getComputerStorageType(void);

/**
 *
 */
void printComputerInfo(byte, const Computer* const);

#endif