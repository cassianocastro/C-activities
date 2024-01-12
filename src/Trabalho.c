#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum
{
    EXIT,
	CRESCENTE,
    DECRESCENTE
}
Options;

const unsigned char TAMANHO_VETOR = 10, LIMITE_RANDOMICO = 101;

void crescente(int* vector)
{
	char auxiliar = 0, assistente = 0;

	for ( register unsigned char i = 1; i < TAMANHO_VETOR; ++i )
    {
		if ( vector[i] < vector[i - 1] )
        {
			auxiliar      = vector[i];
			assistente    = vector[i - 1];
			vector[i - 1] = auxiliar;
			vector[i]     = assistente;

            i = 0;
		}
	}

	puts("\nVetor em ordem crescente:\nIndice\tValor");

	for ( register unsigned char i = 0; i < TAMANHO_VETOR; ++i )
    {
        printf("[%.2d]\t%d\n", i, vector[i]);
    }
}

void decrescente(int* vector)
{
	char auxiliar = 0, assistente = 0;

	for ( register unsigned char i = 1u; i < TAMANHO_VETOR; ++i )
    {
		if ( vector[i] > vector[i - 1] )
        {
			auxiliar      = vector[i];
			assistente    = vector[i - 1];
			vector[i - 1] = auxiliar;
			vector[i]     = assistente;

            i = 0;
		}
	}

	puts("\nVetor em ordem decrescente:\nIndice\tValor");

	for ( register unsigned char i = 0u; i < TAMANHO_VETOR; ++i )
    {
        printf("[%.2d]\t%d\n", i, vector[i]);
    }
}

void gerarVetor(int* vector)
{
	puts("Vetor gerado:");

    srand(time(NULL));

    for ( register unsigned char i = 0u; i < TAMANHO_VETOR; ++i )
    {
		vector[i] = rand() % LIMITE_RANDOMICO;

		printf("[%.2d]\t%d\n", i, vector[i]);
	}
}

const unsigned int getMainMenuChoice(void)
{
    unsigned int choice = 0u;

    printf(
        "\nEscolha o tipo de ordenação:"
        "\n1. Crescente | 2. Decrescente | 0. Sair"
        "\nOpção\? "
    );
    scanf(" %d", &choice);

    return choice;
}

/**
 *
 */
int main(int argc, const char** argv)
{
	setlocale(LC_ALL, "");

    int vector[TAMANHO_VETOR];

	gerarVetor(vector);

	unsigned int option = 0u;

	while ( true )
    {
		option = getMainMenuChoice();

        switch ( option )
        {
			case CRESCENTE:
				crescente(vector);
				break;
			case DECRESCENTE:
				decrescente(vector);
				break;
			default:
				exit(EXIT_SUCCESS);
		}
	}

	return EXIT_SUCCESS;
}