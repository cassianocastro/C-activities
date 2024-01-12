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
int main(int argc, const char* argv[])
{
	setlocale(LC_ALL, "");

	srand(time(NULL));

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