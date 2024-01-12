#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum
{
    EXIT,
	ASCENDING,
    DESCENDING
}
Options;

const unsigned char TAMANHO_VETOR = 10u, LIMITE_RANDOMICO = 101u;

void printVector(int* vector)
{
    puts("\nVetor:\nIndice\tValor");

    for ( register unsigned char i = 0u; i < TAMANHO_VETOR; ++i )
    {
        printf("[%.2d]\t%d\n", i, vector[i]);
    }
}

void ascendingOrder(int* vector)
{
	unsigned char helper = 0u, assistant = 0u;

	for ( register unsigned char i = 1u; i < TAMANHO_VETOR; ++i )
    {
		if ( vector[i] < vector[i - 1] )
        {
			helper        = vector[i];
			assistant     = vector[i - 1];
			vector[i - 1] = helper;
			vector[i]     = assistant;

            i = 0u;
		}
	}
}

void descendingOrder(int* vector)
{
	unsigned char helper = 0u, assistant = 0u;

	for ( register unsigned char i = 1u; i < TAMANHO_VETOR; ++i )
    {
		if ( vector[i] > vector[i - 1] )
        {
			helper        = vector[i];
			assistant     = vector[i - 1];
			vector[i - 1] = helper;
			vector[i]     = assistant;

            i = 0u;
		}
	}
}

void fillVectorWithRandomNumbers(int* vector)
{
    srand(time(NULL));

    for ( register unsigned char i = 0u; i < TAMANHO_VETOR; ++i )
    {
		vector[i] = rand() % LIMITE_RANDOMICO;
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

	fillVectorWithRandomNumbers(vector);
    printVector(vector);

	unsigned int option = 0u;

	while ( true )
    {
		option = getMainMenuChoice();

        switch ( option )
        {
			case ASCENDING:
				ascendingOrder(vector);
                printVector(vector);
				break;
			case DESCENDING:
				descendingOrder(vector);
                printVector(vector);
				break;
			default:
				exit(EXIT_SUCCESS);
		}
	}

	return EXIT_SUCCESS;
}