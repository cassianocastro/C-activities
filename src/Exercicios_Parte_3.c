#include <inttypes.h>
#include <iso646.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned short ushort;

/**
 * @test
 */
void canAlignOutput(void)
{
	int value = 1;

    printf("Justificado a direita  => %5d\n", value);
    printf("Justificado a esquerda => %-5d\n", value);

	uint_fast8_t fast = 190;

	printf("Poder: %hhu\nSizeof: %hhu", fast, sizeof(uint_fast8_t));
}

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
		gets(option);
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

	char option[3] = "\0\0\0";

	printf("\nDeseja realizar outra operação [sim/nao]\? ");
	gets(option);

	printf("\nOpção escolhida: %s", verifyOption(option));

	return EXIT_SUCCESS;
}