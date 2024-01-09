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
    char tipohd;
	char modelo[MAX_SIZE_STR];
	char marca[MAX_SIZE_STR];
	char processador[MAX_SIZE_STR];

    int memoria;
    int hd;
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

Computador* inventario;

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
const unsigned int getMainMenuChoice(void);

#endif