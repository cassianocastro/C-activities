#ifndef LIBRARY_H

#define LIBRARY_H

#include <ctype.h>
#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 50

typedef unsigned char byte;

typedef enum
{
    EXIT,
    CREATE,
    READ,
    DELETE,
    SEARCH
}
Options;

typedef struct
{
	char title[TAMANHO];
	char author[TAMANHO];
	char publishing[TAMANHO];
	char subject[TAMANHO];

	unsigned short release;
}
Book;

Book library[10];

#endif