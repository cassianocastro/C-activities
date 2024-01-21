#ifndef COMPUTER_CONTROLLER_H

#define COMPUTER_CONTROLLER_H

#include <ctype.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../model/ComputerModel.h"
#include "../view/ComputerView.h"

/**
 *
 */
typedef enum
{
	EXIT,
    CREATE,
    READ,
    UPDATE,
    DELETE,
    SEARCH
}
Opcoes;

/**
 *
 */
typedef enum
{
	MARK,
    STORAGE_TYPE,
    STORAGE,
    MEMORY,
    MODEL,
    PROCESSOR
}
Dados;

extern Computer* inventary;

extern unsigned short numero;

/**
 *
 */
void start(void);

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
void addOneComputer(void);

/**
 *
 */
void addSeveralComputers(void);

#endif