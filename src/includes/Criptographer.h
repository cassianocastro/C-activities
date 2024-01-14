#ifndef CRIPTOGRAPHER_H

#define CRIPTOGRAPHER_H

#ifdef CRIPTOGRAPHER_V1

#include <iso646.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_FRASE 100

typedef unsigned char byte;

typedef enum
{
    SAIR,
    CRIPTOGRAFAR,
    DESCRIPTOGRAFAR
}
Options;

#elif CRIPTOGRAPHER_V2

#include <iso646.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_FRASE 100

typedef unsigned int byte;

typedef enum
{
    SAIR,
    CRIPTOGRAFAR,
    DESCRIPTOGRAFAR
}
Options;

#elif CRIPTOGRAPHER_ZANINI

#include <iso646.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#endif

#endif