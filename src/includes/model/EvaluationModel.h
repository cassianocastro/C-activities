#ifndef EVALUATION_MODEL_H

#define EVALUATION_MODEL_H

#define TAM 50
#define TAM_PROCESS 20
#define TAM_COR 20

/**
 *
 */
typedef struct
{
	int ID;
    int memory;
    int storage;

    float screen;

    char type;
	char mark[TAM];
	char model[TAM];
	char processor[TAM_PROCESS];
	char color[TAM_COR];
}
Computer;

#endif