#ifndef CRIPTOGRAPHER_H

#define CRIPTOGRAPHER_H

#include <iso646.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef CRIPTOGRAPHER_V1

#define TAMANHO_FRASE 100

typedef unsigned char byte;

typedef enum
{
    SAIR,
    CRIPTOGRAFAR,
    DESCRIPTOGRAFAR
}
Options;

/**
 *
 */
void criptografar(char*);

/**
 *
 */
void descriptografar(char*);

#elif defined CRIPTOGRAPHER_V2

#define TAMANHO_FRASE 100

typedef unsigned int byte;

typedef enum
{
    SAIR,
    CRIPTOGRAFAR,
    DESCRIPTOGRAFAR
}
Options;

/**
 *
 */
void criptografar(char*);

/**
 *
 */
void descriptografar(char*);

#elif defined CRIPTOGRAPHER_ZANINI

/**
 *
 */
void cripto(char*);

/**
 *
 */
void decripto(char*);

#endif

#endif