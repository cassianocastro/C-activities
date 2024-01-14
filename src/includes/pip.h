#ifndef PIP_H

#define PIP_H

#include <ctype.h>
#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

enum Meses
{
    JANEIRO = 1,
    FEVEREIRO,
    MARCO,
    ABRIL,
    MAIO,
    JUNHO,
    JULHO,
    AGOSTO,
    SETEMBRO,
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO
};

/**
 *
 */
int geraPar(int);

/**
 *
 */
int geraImpar(int);

/**
 *
 */
int geraprimo(int);

/**
 *
 */
char verifyResponse(char);

/**
 *
 */
bool isValid(int, int, int);

/**
 *
 */
char* nameOfThis(byte);

#endif