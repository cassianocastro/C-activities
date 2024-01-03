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
	byte dia;
    byte mes;

    unsigned short int ano;
}
Data_nascimento;

/**
 *
 */
typedef struct
{
	Data_nascimento dn;

    byte idade;

    char nome[51];
    char cidade[21];
    char telefone[17];
    char sexo;
}
Pessoa;

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

Pessoa* agenda;

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
void printContact(const Pessoa* const);

#endif