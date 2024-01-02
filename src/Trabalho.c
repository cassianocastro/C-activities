#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

const unsigned char TAMANHO_VETOR = 10, LIMITE_RANDOMICO = 101;

typedef enum
{
	CRESCENTE,
    DECRESCENTE
}
Opcoes;

void crescente(int* vetor)
{
	char pos = 0, auxiliar = 0, assistente = 0;

	for ( pos = 1; pos < TAMANHO_VETOR; pos++ )
    {
		if ( vetor[pos] < vetor[pos - 1] )
        {
			auxiliar   	   = vetor[pos];
			assistente 	   = vetor[pos - 1];
			vetor[pos - 1] = auxiliar;
			vetor[pos]     = assistente;
			pos 	       = 0;
		}
	}

	puts("\nVetor em ordem crescente:\nIndice\tValor");

	for ( pos = 0; pos < TAMANHO_VETOR; printf("[%.2d]\t%d\n", pos, vetor[pos++]) );
}

void decrescente(int* vetor)
{
	char pos = 0, auxiliar = 0, assistente = 0;

	for ( pos = 1; pos < TAMANHO_VETOR; pos++ )
    {
		if ( vetor[pos] > vetor[pos - 1] )
        {
			auxiliar       = vetor[pos];
			assistente     = vetor[pos - 1];
			vetor[pos - 1] = auxiliar;
			vetor[pos] 	   = assistente;
			pos 	       = 0;
		}
	}

	puts("\nVetor em ordem decrescente:\nIndice\tValor");

	for ( pos = 0; pos < TAMANHO_VETOR; printf("[%.2d]\t%d\n", pos, vetor[pos++]) );
}

void gerarVetor(int* vetor)
{
	char pos = 0;

	puts("Vetor gerado:");

    for ( ; pos < TAMANHO_VETOR; pos++ )
    {
		vetor[pos] = rand() % LIMITE_RANDOMICO;

		printf("[%.2d]\t%d\n", pos, vetor[pos]);
	}
}

/**
 *
 */
int main(int argc, const char* argv[])
{
	setlocale(LC_ALL, "");

	srand(time(NULL));

	Opcoes opcao;
    int vetor[TAMANHO_VETOR];

	gerarVetor(vetor);

	while ( true )
    {
		printf(
            "\nEscolha o tipo de ordenação:\n"
			"0 - Ordem crescente | 1 - Ordem decrescente | Outra tecla - Sair"
			"\nOpção\? "
        );
		scanf(" %d", &opcao);

        switch ( opcao )
        {
			case CRESCENTE:
				crescente(vetor);
				break;
			case DECRESCENTE:
				decrescente(vetor);
				break;
			default:
				exit(EXIT_SUCCESS);
		}
	}

	return EXIT_SUCCESS;
}