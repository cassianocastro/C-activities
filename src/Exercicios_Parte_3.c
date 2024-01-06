#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <iso646.h>
#include <locale.h>

typedef unsigned short ushort;

const ushort TAMANHO_MATRIZ = 6, LIMITE_RANDOMICO = 100;

void testandoAlinhamento( void )
{
	int valor = 1;

    printf("Justificado a direita  => %5d\n",valor);
    printf("Justificado a esquerda => %-5d\n",valor);

	uint_fast8_t fast = 190;

	printf("Poder: %hhu\nSizeof: %hhu", fast, sizeof( uint_fast8_t ));
}

void gerarMatriz( void )
{
	ushort lin = 0, col = 0;
	ushort m[TAMANHO_MATRIZ][TAMANHO_MATRIZ];

	printf("Matriz gerada:\n\n");

	for ( lin = 0; lin < TAMANHO_MATRIZ; lin++ )
    {
		for ( col = 0; col < TAMANHO_MATRIZ; col++ )
        {
			m[lin][col] = rand() % LIMITE_RANDOMICO;

			printf("\t%.2d", m[lin][col]);
		}

		printf("\n");
	}
}

char* verificarOpcao( char* opcao )
{
	while ( strcmp(opcao, "sim") != 0 and strcmp(opcao, "nao") != 0 )
    {
		printf("Resposta inv�lida. Digite novamente: ");
		gets( opcao );
	}

	return opcao;
}

int main( void )
{
	setlocale ( LC_ALL, "" );
	srand ( time(NULL) );

    gerarMatriz();

	char opcao[3] = "\0\0\0";

	printf ("\nDeseja realizar outra opera��o [sim/nao]? ");
	gets   ( opcao );

	printf ("\nOp��o escolhida: %s", verificarOpcao( opcao ));

	return 0;
}