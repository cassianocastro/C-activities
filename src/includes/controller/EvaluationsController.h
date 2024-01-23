#ifndef EVALUATION_CONTROLLER_H

#define EVALUATION_CONTROLLER_H

#include <errno.h>
#include <inttypes.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../model/Evaluation.h"
#include "../view/EvaluationsView.h"

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
bool ok(int);

/**
 *
 */
void alterado(Computer*);

/**
 *
 */
void chooseFile(void);

#endif