#ifndef PCS_H

#define PCS_H

#include <ctype.h>
#include <iso646.h>
#include <inttypes.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_STR 30

typedef unsigned char byte;

typedef struct
{
    char storageType;
	char model[MAX_SIZE_STR];
	char mark[MAX_SIZE_STR];
	char processor[MAX_SIZE_STR];

    int memory;
    int storage;
}
Computer;

typedef enum
{
	CREATE = 1,
	READ,
	UPDATE,
	DELETE,
	SEARCH
}
Options;

typedef enum
{
	MARK = 1,
	STORAGE_TYPE,
	STORAGE,
	MEMORY,
	MODEL,
	PROCESSOR
}
Data;

unsigned short int num;

Computer* inventary;

/**
 *
 */
void addComputer(void);

/**
 *
 */
void showComputers(void);

/**
 *
 */
void updateComputer(void);

/**
 *
 */
void deleteComputer(void);

/**
 *
 */
void searchComputer(void);

/**
 *
 */
void preenchimento_dados(byte);

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