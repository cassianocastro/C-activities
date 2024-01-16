#ifdef EX_P1

#include <inttypes.h>
#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned char byte;

void maior(int x, int y, int* response)
{
	if ( x > y )
        *response = x;
	else if ( x == y )
        *response = 0;
	else
        *response = y;
}

void brincarComNumeros(void)
{
	int a = 0, b = 0, response = 0;

	printf("\nDigite um número: ");
	scanf("%d", &a);

	printf("Outro...: ");
	scanf("%d", &b);

	maior(a, b, &response);

	if ( response not_eq 0 )
        printf("O maior número é: %d\n", response);
    else
        puts("\nOs números são iguais.");
}

byte maiorNoVetor(byte* vetor, byte tamanho)
{
	byte maior = 0;

	for ( register byte i = 0; i < tamanho; ++i )
    {
		if ( vetor[i] > maior )
        {
			maior = vetor[i];
        }
	}

	return maior;
}

void generateVector(void)
{
	const byte SIZE = 10, RANDOM_LIMIT = 101;

    byte vetor[SIZE];

    srand(time(NULL));

	puts("\nVetor gerado:");

	for ( register byte i = 0; i < SIZE; ++i )
    {
		vetor[i] = rand() % RANDOM_LIMIT;

        printf("%.2d - ", vetor[i]);
	}

	printf("\nO maior valor presente no vetor é: %.2d\n", maiorNoVetor(vetor, SIZE));
}

/**
 *
 */
int main(void)
{
	setlocale(LC_ALL, "");

	byte option = 0;

	printf(
        "Escolha uma opção:"
		"\n1. Brincar com Números | 2. Gerar um Vetor"
		"\nOpção\? "
    );
	scanf("%hhu", &option);

	if ( option == 1 )
		brincarComNumeros();
	else if ( option == 2 )
		generateVector();
	else
		puts("Opção inválida!");

	return EXIT_SUCCESS;
}

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

const ushort VECTOR_SIZE = 10, RANDOM_LIMIT = 101;

void fillVectorWithRandomNumbers(ushort* vector)
{
    srand(time(NULL));

	for ( register ushort i = 0; i < VECTOR_SIZE; ++i )
    {
		vector[i] = rand() % RANDOM_LIMIT;
	}
}

void printVector(ushort* vector)
{
	puts("\nÍndice\tValor");

	for ( register ushort i = 0u; i < VECTOR_SIZE; ++i )
    {
        printf("[%hu]\t%.2hu\n", i, vector[i]);
    }

    printf("\n");
}

void reverseVector(ushort* vector)
{
	ushort helper = 0u;

	for ( register ushort i = 0u, j = 1u; i < (VECTOR_SIZE / 2); ++i, ++j )
    {
		helper    = vector[i];
		vector[i] = vector[VECTOR_SIZE - j];

		vector[VECTOR_SIZE - j] = helper;
	}
}

void ascendingOrder(ushort* vector)
{
    ushort helper = 0u, assistant = 0u;

    for ( register ushort i = 1u; i < VECTOR_SIZE; ++i )
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

void descendingOrder(ushort* vector)
{
    ushort helper = 0u, assistant = 0u;

    for ( register ushort i = 1u; i < VECTOR_SIZE; ++i )
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

void orderVector(ushort* vector)
{
	ushort order = 0u;

	printf(
        "\nSelecione o tipo de ordenamento:"
		"\n1. Crescente | 2. Decrescente"
		"\nOpção\? "
    );
	scanf("%hu", &order);

	if ( order == 1 )
    {
		puts("\nVetor em ordem crescente:");

        ascendingOrder(vector);
	}
    else if ( order == 2 )
    {
		puts("\nVetor em ordem decrescente:");

        descendingOrder(vector);
	}
    else
    {
        puts("\nOpção inválida!");
    }

	printVector(vector);
}

const ushort getMaxValueFromVector(ushort* vector)
{
	ushort maior = 0u;

	for ( register ushort i = 0; i < VECTOR_SIZE; ++i )
    {
		if ( vector[i] > maior )
        {
            maior = vector[i];
        }
	}

	return maior;
}

/**
 *
 */
int main(void)
{
	setlocale(LC_ALL, "");

    ushort vetor[VECTOR_SIZE];

    fillVectorWithRandomNumbers(vetor);

    puts("Vetor gerado:");
	printVector(vetor);

    unsigned int option = 0u;

	printf(
        "\nEscolha uma opção referente ao vetor:"
		"\n1. Invertê-lo | 2. Ordená-lo | 3. Obter seu maior valor"
		"\nOpção\? "
    );
	scanf("%1d", &option);

	switch ( option )
    {
		case REVERSE:
            puts("\nVetor invertido:");

			reverseVector(vetor);
            printVector(vetor);
			break;
        case ORDER:
			orderVector(vetor);
			break;
		case MAX_VAL:
            printf("\nMaior valor no vetor: %.2hu", getMaxValueFromVector(vetor));
			break;
		default:
			puts("\nOpção inválida!");
	}

	return EXIT_SUCCESS;
}

#elif EX_P3

#endif