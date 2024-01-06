#include <inttypes.h>
#include <iso646.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned short ushort;

const ushort TAMANHO_MATRIZ = 6, LIMITE_RANDOMICO = 100;

/**
 * @test
 */
void canAlignOutput(void)
{
	int valor = 1;

    printf("Justificado a direita  => %5d\n", valor);
    printf("Justificado a esquerda => %-5d\n", valor);

	uint_fast8_t fast = 190;

	printf("Poder: %hhu\nSizeof: %hhu", fast, sizeof(uint_fast8_t));
}

/**
 *
 */
void generateMatrix(void)
{
	ushort m[TAMANHO_MATRIZ][TAMANHO_MATRIZ];

	puts("Matriz gerada:\n");

	for ( register ushort i = 0; i < TAMANHO_MATRIZ; ++i )
    {
		for ( register ushort j = 0; j < TAMANHO_MATRIZ; ++j )
        {
			m[i][j] = rand() % LIMITE_RANDOMICO;

			printf("\t%.2d", m[i][j]);
		}

		puts("\n");
	}
}

/**
 *
 */
char* verifyOption(char* opcao)
{
	while ( strcmp(opcao, "sim") != 0 and strcmp(opcao, "nao") != 0 )
    {
		printf("Resposta inválida. Digite novamente: ");
		gets(opcao);
	}

	return opcao;
}

/**
 *
 */
int main(void)
{
	setlocale(LC_ALL, "");

	srand(time(NULL));

    generateMatrix();

	char opcao[3] = "\0\0\0";

	printf("\nDeseja realizar outra operação [sim/nao]\? ");
	gets(opcao);

	printf("\nOpção escolhida: %s", verifyOption(opcao));

	return EXIT_SUCCESS;
}