#ifndef COMPUTER_MODEL_H

#define COMPUTER_MODEL_H

#define TAM_STRING 30

typedef unsigned char byte;

/**
 *
 */
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

#endif