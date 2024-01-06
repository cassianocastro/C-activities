#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <iso646.h>

typedef unsigned short int Ushort;

const Ushort TAMANHO = 10, LIMITE_RANDOMICO = 101;

void escrever ( Ushort *vetor )
{
	Ushort indice = 0, indice2 = 0;

	puts ("\n�ndice\tValor");

	for ( ; indice2 < TAMANHO; printf("[%hu]\t%.2hu\n", indice2++, vetor[indice2]));

    printf("\n");
}

void maiornovetor( Ushort *vetor )
{
	Ushort indice = 0, maior = 0;

	for ( indice = 0; indice < TAMANHO; indice++ )
    {
		if ( vetor[indice] > maior ) maior = vetor[indice];
	}

	printf("\nO maior valor presente no vetor �: %.2hu", maior);
}

void inverter( Ushort *vetor )
{
	Ushort indice = 0, auxiliar = 0, contador = 0;

	puts ("\nVetor invertido:");

	for ( indice = 0, contador = 1; indice < (TAMANHO / 2); indice++, contador++ )
    {
		auxiliar 			  	  = vetor[indice];
		vetor[indice] 			  = vetor[TAMANHO - contador];
		vetor[TAMANHO - contador] = auxiliar;
	}

	escrever( vetor );
}

void ordenar( Ushort *vetor )
{
	Ushort indice = 0, auxiliar = 0, assistente = 0, tipo = 0;

	printf(
        "\nSelecione o tipo de ordenamento:\n"
		"1. Crescente | 2. Decrescente"
		"\nOp��o? "
    );
	scanf ( "%hu", &tipo );

	if ( tipo == 1 )
    {
		puts ("\nVetor em ordem crescente:");

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
		puts ("\nVetor em ordem decrescente:");

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
        puts ("\nOp��o inv�lida!");
    }

	escrever( vetor );
}

void converterMoeda( void )
{
	float real = 0.0f, dolar = 0.0f;

	printf("\nInforme o valor em R$: ");
	scanf("%f", &real);

	printf("O valor atual do d�lar: ");
	scanf("%f", &dolar);

	printf("\nA quantia correspondente em d�lares � de: U$ %.2f", real / dolar);
}

void converterTemperatura( void )
{
	float celsius = 0.0f; unsigned char opcao = 0;

	printf ("\nInforme a temperatura em graus Celsius: ");
	scanf  ( "%f", &celsius );

	printf ("\nDigite 1 para convers�o em Farenheit ou 0 para Kelvin. Op��o? ");
	scanf  ( "%hhu", &opcao );

	printf (
        "A temperatura em graus Kelvin �: %.1f",
        ( opcao not_eq 1 ) ? (celsius + 273.15) : ((celsius * 9 / 5) + 32)
    );
}

typedef enum
{
	INVERSAO = 1,
    MAIOR,
    ORDENACAO
}
Opcao;

int main( void )
{
	setlocale( LC_ALL, "" );

    srand( time(NULL) );

	Opcao opcao; Ushort indice = 0, vetor[TAMANHO];

	puts ("Vetor gerado:");

	for ( indice = 0; indice < TAMANHO; indice++ )
    {
		vetor[indice] = rand() % LIMITE_RANDOMICO;
	}

	escrever( vetor );

	printf(
        "\nEscolha uma op��o referente ao vetor:\n"
		"1. Invert�-lo | 2. Orden�-lo | 3. Descobrir seu maior n�mero"
		"\nOp��o? "
    );
	scanf( "%d", &opcao );

	switch ( opcao )
    {
		case INVERSAO:
			inverter( vetor );
			break;
		case MAIOR:
			maiornovetor( vetor );
			break;
		case ORDENACAO:
			ordenar( vetor );
			break;
		default:
			puts ("\nOp��o inv�lida!");
	}

	converterTemperatura();

	return ( EXIT_SUCCESS );
}