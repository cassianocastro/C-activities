#ifndef COMPUTER_H

#define COMPUTER_H

#include <ctype.h>
#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_STRING 30

typedef struct
{
    char storageType;
    char model[TAM_STRING];
    char mark[TAM_STRING];
    char processor[TAM_STRING];

    int memory;
    int storage;
}
Computer;

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

typedef unsigned char byte;

Computer* inventary;

unsigned short numero;

#endif