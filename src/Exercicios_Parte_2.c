#include <iso646.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef unsigned short int Ushort;

typedef enum
{
	INVERSAO = 1,
    MAIOR,
    ORDENACAO
}
Opcao;

const Ushort TAMANHO = 10, LIMITE_RANDOMICO = 101;

void escrever(Ushort* vetor)
{
	Ushort indice = 0, indice2 = 0;

	puts("\nÍndice\tValor");

	for ( ; indice2 < TAMANHO; printf("[%hu]\t%.2hu\n", indice2++, vetor[indice2]));

    printf("\n");
}

void maiornovetor(Ushort* vetor)
{
	Ushort maior = 0;

	for ( register Ushort i = 0; i < TAMANHO; ++i )
    {
		if ( vetor[i] > maior ) maior = vetor[i];
	}

	printf("\nO maior valor presente no vetor é: %.2hu", maior);
}

void inverter(Ushort* vetor)
{
	Ushort indice = 0, auxiliar = 0, contador = 0;

	puts("\nVetor invertido:");

	for ( indice = 0, contador = 1; indice < (TAMANHO / 2); indice++, contador++ )
    {
		auxiliar 			  	  = vetor[indice];
		vetor[indice] 			  = vetor[TAMANHO - contador];
		vetor[TAMANHO - contador] = auxiliar;
	}

	escrever(vetor);
}

void ordenar(Ushort* vetor)
{
	Ushort indice = 0, auxiliar = 0, assistente = 0, tipo = 0;

	printf(
        "\nSelecione o tipo de ordenamento:\n"
		"1. Crescente | 2. Decrescente"
		"\nOpção\? "
    );
	scanf("%hu", &tipo);

	if ( tipo == 1 )
    {
		puts("\nVetor em ordem crescente:");

		for ( indice = 1; indice < TAMANHO; indice++ )
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

		for ( indice = 1; indice < TAMANHO; indice++ )
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

	escrever(vetor);
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
        "A temperatura em graus Kelvin é: %.1f",
        ( opcao not_eq 1 ) ? (celsius + 273.15) : ((celsius * 9 / 5) + 32)
    );
}

/**
 *
 */
int main(void)
{
	setlocale(LC_ALL, "");

    Ushort vetor[TAMANHO];

    srand(time(NULL));

	puts("Vetor gerado:");

	for ( register Ushort i = 0; i < TAMANHO; ++i )
    {
		vetor[i] = rand() % LIMITE_RANDOMICO;
	}

	escrever(vetor);

    unsigned int option = 0u;

	printf(
        "\nEscolha uma opção referente ao vetor:\n"
		"1. Invertê-lo | 2. Ordená-lo | 3. Descobrir seu maior número"
		"\nOpção\? "
    );
	scanf("%d", &option);

	switch ( option )
    {
		case INVERSAO:
			inverter(vetor);
			break;
		case MAIOR:
			maiornovetor(vetor);
			break;
		case ORDENACAO:
			ordenar(vetor);
			break;
		default:
			puts("\nOpção inválida!");
	}

	converterTemperatura();

	return EXIT_SUCCESS;
}