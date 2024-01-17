#ifndef VALIDATION_H

#define VALIDATION_H

#include <inttypes.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdio.h>

/**
 *
 */
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
bool validadata(uint8_t, uint8_t, uint16_t);

#endif