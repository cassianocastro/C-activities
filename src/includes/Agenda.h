#ifndef AGENDA_H

#define AGENDA_H

#include <ctype.h>
#include <iso646.h>
#include <inttypes.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./Validacao.h"

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
Data_nascimento;

/**
 *
 */
typedef struct
{
	Data_nascimento dn;

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
Opcoes;

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
Dados;

const unsigned short int CURRENT_YEAR = 2024;

Contact* contacts;

unsigned short int num;

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

#endif