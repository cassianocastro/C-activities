#include <iso646.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef unsigned short int ushort;

typedef enum
{
	INVERSAO = 1,
    ORDENACAO,
    MAIOR
}
Opcao;

const ushort VECTOR_SIZE = 10, RANDOM_LIMIT = 101;

void printVector(ushort* vector)
{
	puts("\nÍndice\tValor");

	for ( register ushort i = 0u; i < VECTOR_SIZE; ++i )
    {
        printf("[%hu]\t%.2hu\n", i, vector[i]);
    }

    printf("\n");
}

void maiornovetor(ushort* vector)
{
	ushort maior = 0u;

	for ( register ushort i = 0; i < VECTOR_SIZE; ++i )
    {
		if ( vector[i] > maior )
        {
            maior = vector[i];
        }
	}

	printf("\nO maior valor presente no vetor é: %.2hu", maior);
}

void inverter(ushort* vector)
{
	ushort helper = 0u;

	puts("\nVetor invertido:");

	for ( register ushort i = 0u, j = 1u; i < (VECTOR_SIZE / 2); ++i, ++j )
    {
		helper    = vector[i];
		vector[i] = vector[VECTOR_SIZE - j];

		vector[VECTOR_SIZE - j] = helper;
	}

	printVector(vector);
}

void ordenar(ushort* vetor)
{
	ushort indice = 0, auxiliar = 0, assistente = 0, tipo = 0;

	printf(
        "\nSelecione o tipo de ordenamento:\n"
		"1. Crescente | 2. Decrescente"
		"\nOpção\? "
    );
	scanf("%hu", &tipo);

	if ( tipo == 1 )
    {
		puts("\nVetor em ordem crescente:");

		for ( indice = 1; indice < VECTOR_SIZE; indice++ )
        {
			if ( vetor[indice] < vetor[indice - 1] )
            {
				auxiliar       	  = vetor[indice];
				assistente        = vetor[indice - 1];
				vetor[indice - 1] = auxiliar;
				vetor[indice]     = assistente;
				indice            = 0;
			}
		}
	}
    else if ( tipo == 2 )
    {
		puts("\nVetor em ordem decrescente:");

		for ( indice = 1; indice < VECTOR_SIZE; indice++ )
        {
			if ( vetor[indice] > vetor[indice - 1] )
            {
				auxiliar       	  = vetor[indice];
				assistente        = vetor[indice - 1];
				vetor[indice - 1] = auxiliar;
				vetor[indice]     = assistente;
				indice            = 0;
			}
		}
	}
    else
    {
        puts("\nOpção inválida!");
    }

	printVector(vetor);
}

void converterMoeda(void)
{
	float real = 0.0f, dolar = 0.0f;

	printf("\nInforme o valor em R$: ");
	scanf("%f", &real);

	printf("O valor atual do dólar: ");
	scanf("%f", &dolar);

	printf("\nA quantia correspondente em dólares é de: U$ %.2f", real / dolar);
}

void converterTemperatura(void)
{
	float celsius = 0.0f;

	printf("\nInforme a temperatura em graus Celsius: ");
	scanf("%f", &celsius);

    unsigned char opcao = 0;

	printf("\nDigite 1 para conversão em Farenheit ou 0 para Kelvin. Opção\? ");
	scanf("%hhu", &opcao);

	printf(
        "A temperatura em graus Kelvin é: %.1f\n",
        ( opcao not_eq 1 ) ? (celsius + 273.15) : ((celsius * 9 / 5) + 32)
    );
}

/**
 *
 */
int main(void)
{
	setlocale(LC_ALL, "");

    ushort vetor[VECTOR_SIZE];

    srand(time(NULL));

	puts("Vetor gerado:");

	for ( register ushort i = 0; i < VECTOR_SIZE; ++i )
    {
		vetor[i] = rand() % RANDOM_LIMIT;
	}

	printVector(vetor);

    unsigned int option = 0u;

	printf(
        "\nEscolha uma opção referente ao vetor:"
		"\n1. Invertê-lo | 2. Ordená-lo | 3. Descobrir seu maior número"
		"\nOpção\? "
    );
	scanf("%d", &option);

	switch ( option )
    {
		case INVERSAO:
			inverter(vetor);
			break;
        case ORDENACAO:
			ordenar(vetor);
			break;
		case MAIOR:
			maiornovetor(vetor);
			break;
		default:
			puts("\nOpção inválida!");
	}

	// converterTemperatura();

	return EXIT_SUCCESS;
}