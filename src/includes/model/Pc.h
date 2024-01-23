#ifndef PCS_MODEL_H

#define PCS_MODEL_H

#define MAX_SIZE_STR 30

typedef unsigned char byte;

/**
 *
 */
typedef struct
{
    char storageType;
	char model[MAX_SIZE_STR];
	char mark[MAX_SIZE_STR];
	char processor[MAX_SIZE_STR];

    int memory;
    int storage;
}
Computer;

extern unsigned short int num;

extern Computer* inventary;

#endif