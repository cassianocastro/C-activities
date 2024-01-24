#ifndef AGENDA_VIEW_H

#define AGENDA_VIEW_H

#include <inttypes.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdio.h>

#include "../model/Agenda.h"

/**
 *
 */
const unsigned int showMainMenu(void);

/**
 *
 */
const unsigned int showUpdateMenu(void);

/**
 *
 */
void showContactForm(Contact* const);

/**
 *
 */
void printContact(const Contact* const);

/**
 *
 */
byte getContactID(void);

/**
 *
 */
char getContactSex(void);

/**
 *
 */
BirthDate getContactBirthDate(void);

/**
 *
 */
void getContactName(char* const);

/**
 *
 */
void getContactCity(char* const);

/**
 *
 */
void getContactPhone(char* const);

#endif