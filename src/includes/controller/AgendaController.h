#ifndef AGENDA_CONTROLLER_H

#define AGENDA_CONTROLLER_H

#include <ctype.h>
#include <inttypes.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../pip.h"
#include "../model/Agenda.h"
#include "../view/AgendaView.h"

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
Options;

/**
 *
 */
typedef enum
{
	NAME = 1,
	SEX,
	BIRTHDATE,
	CITY,
	PHONE
}
Data;

/**
 *
 */
void start(void);

/**
 *
 */
void addContact(void);

/**
 *
 */
void showContacts(void);

/**
 *
 */
void updateContact(void);

/**
 *
 */
void deleteContact(void);

/**
 *
 */
void searchContact(void);

#endif