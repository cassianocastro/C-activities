#include <iso646.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned short ushort;

/**
 *
 */
void generateMatrix(void)
{
    const ushort MATRIX_SIZE = 6, RANDOM_LIMIT = 100;

	ushort m[MATRIX_SIZE][MATRIX_SIZE];

    srand(time(NULL));

	puts("Matriz gerada:\n");

	for ( register ushort i = 0; i < MATRIX_SIZE; ++i )
    {
		for ( register ushort j = 0; j < MATRIX_SIZE; ++j )
        {
			m[i][j] = rand() % RANDOM_LIMIT;

			printf("\t%.2d", m[i][j]);
		}

		puts("\n");
	}
}

/**
 *
 */
char* verifyOption(char* option)
{
	while ( strcmp(option, "sim") != 0 and strcmp(option, "nao") != 0 )
    {
		printf("Resposta inválida. Digite novamente: ");
		scanf(" %[^\n]s", option);
	}

	return option;
}

/**
 *
 */
int main(void)
{
	setlocale(LC_ALL, "");

    generateMatrix();

	char option[] = "\0\0\0";

	printf("\nDeseja realizar outra operação [sim/nao]\? ");
	scanf(" %[^\n]s", option);

	printf("\nOpção escolhida: %s\n", verifyOption(option));

	return EXIT_SUCCESS;
}