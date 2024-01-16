#ifndef EXERCISES_H

#define EXERCISES_H

#ifdef EX_P1

#include <inttypes.h>
#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned char byte;

#elif EX_P2

#include <iso646.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef unsigned short int ushort;

typedef enum
{
	REVERSE = 1,
    ORDER,
    MAX_VAL
}
Options;

extern const ushort VECTOR_SIZE, RANDOM_LIMIT;

#elif EX_P3

#include <iso646.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned short ushort;

#endif

#endif