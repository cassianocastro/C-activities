#ifndef EVALUATION_H

#define EVALUATION_H

#include <errno.h>
#include <inttypes.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50
#define TAM_PROCESS 20
#define TAM_COR 20

typedef enum
{
	EXIT,
	CREATE,
	READ,
	SEARCH,
	UPDATE,
	DELETE,
	CHOOSE_FILE
}
Options;

typedef enum
{
	TYPE = 1,
	SCREEN,
	MARK,
	MODEL,
	PROCESSOR,
	COLOR,
	MEMORY,
	STORAGE
}
Data;

typedef struct
{
	int ID;
    int memory;
    int storage;

    float screen;

    char type;
	char mark[TAM];
	char model[TAM];
	char processor[TAM_PROCESS];
	char color[TAM_COR];
}
Computer;

FILE* arquivo;

char nome_arquivo[TAM];

Computer computer;

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
void printComputer(const Computer* const);

/**
 *
 */
bool ok(int*);

/**
 *
 */
void alterado(Computer*);

/**
 *
 */
void chooseFile(void);

/**
 *
 */
unsigned int getComputerID(void);

/**
 *
 */
void showComputerForm(unsigned short int);

/**
 *
 */
const unsigned int getMainMenuChoice(void);

/**
 *
 */
const unsigned int getUpdateMenuChoice(void);

#endif