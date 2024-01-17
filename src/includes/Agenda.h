#ifndef AGENDA_H

#define AGENDA_H

#include <ctype.h>
#include <inttypes.h>
#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./Validation.h"

typedef unsigned char byte;

/**
 *
 */
typedef struct
{
	byte day;
    byte month;

    unsigned short int year;
}
BirthDate;

/**
 *
 */
typedef struct
{
	BirthDate dn;

    byte age;

    char name[51];
    char city[21];
    char phone[17];
    char sex;
}
Contact;

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

extern const unsigned short int CURRENT_YEAR;

extern Contact* contacts;

extern unsigned short int num;

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

/**
 *
 */
void showContactForm(byte);

/**
 *
 */
void printContact(const Contact* const);

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
byte getContactID(void);

#endif