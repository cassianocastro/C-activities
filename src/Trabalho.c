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

const unsigned char VECTOR_SIZE = 10u, RANDOM_LIMIT = 101u;

void printVector(int* vector)
{
    puts("\nVetor:\nIndice\tValor");

    for ( register unsigned char i = 0u; i < VECTOR_SIZE; ++i )
    {
        printf("[%.2d]\t%d\n", i, vector[i]);
    }
}

void ascendingOrder(int* vector)
{
	unsigned char helper = 0u, assistant = 0u;

	for ( register unsigned char i = 1u; i < VECTOR_SIZE; ++i )
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

	for ( register unsigned char i = 1u; i < VECTOR_SIZE; ++i )
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

    for ( register unsigned char i = 0u; i < VECTOR_SIZE; ++i )
    {
		vector[i] = rand() % RANDOM_LIMIT;
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
    scanf(" %1d", &choice);

    return choice;
}

/**
 *
 */
int main(int argc, const char** argv)
{
	setlocale(LC_ALL, "");

    int vector[VECTOR_SIZE];

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