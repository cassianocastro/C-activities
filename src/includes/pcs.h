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

typedef unsigned char Byte;

typedef struct
{
    char storageType;
	char model[MAX_SIZE_STR];
	char mark[MAX_SIZE_STR];
	char processor[MAX_SIZE_STR];

    int memory;
    int storage;
}
Computador;

typedef enum
{
	CREATE = 1,
	READ,
	UPDATE,
	DELETE,
	SEARCH
}
Opcoes;

typedef enum
{
	MARK = 1,
	STORAGE_TYPE,
	STORAGE,
	MEMORY,
	MODEL,
	PROCESSOR
}
Dados;

unsigned short int num;

Computador* inventary;

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
void preenchimento_dados(Byte);

/**
 *
 */
void printComputerInfo(Byte, const Computador* const);

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
const Byte getComputerID(void);

#endif