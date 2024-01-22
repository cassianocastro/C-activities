#ifndef PCS_CONTROLLER_H

#define PCS_CONTROLLER_H

#include <ctype.h>
#include <iso646.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../model/Pcs.h"
#include "../view/PcsView.h"

/**
 *
 */
typedef enum
{
	CREATE = 1,
	READ,
	UPDATE,
	DELETE,
	SEARCH
}
Options;

/**
 *
 */
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

extern unsigned short int num;

extern Computer* inventary;

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

#endif