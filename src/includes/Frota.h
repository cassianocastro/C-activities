#ifndef FROTA_H

#define FROTA_H

#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 20

typedef unsigned char byte;

typedef enum
{
    EXIT,
    CREATE,
    READ,
    DELETE
}
Options;

typedef struct
{
	char model[STRING_SIZE];
	char mark[STRING_SIZE];
	char placa[STRING_SIZE];
	char color[STRING_SIZE];

	unsigned short release;
}
Car;

Car frota[10];

const unsigned int ARRAY_SIZE = 10u;

#endif