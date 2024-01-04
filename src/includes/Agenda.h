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
	NOME = 1,
	SEXO,
	DATA,
	CIDADE,
	FONE
}
Dados;

const unsigned short int ANO_ATUAL = 2021;

Contact* contacts;

unsigned short int num;

/**
 *
 */
void dados(byte);

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
void printContact(const Contact* const);

/**
 *
 */
const unsigned int showMainMenu(void);

#endif