#include <inttypes.h>
#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char Byte;

void maior(int x, int y, int* resp)
{
	if ( x > y )
        *resp = x;
	else if ( x == y )
        *resp = 0;
	else
        *resp = y;
}

void brincarComNumeros(void)
{
	int a = 0, b = 0, resposta = 0;

	printf("\nDigite um n�mero: ");
	scanf("%d", &a);

	printf("Outro...: ");
	scanf("%d", &b);

	maior(a, b, &resposta);

	if ( resposta not_eq 0 )
        printf("O maior n�mero �: %d", resposta);
    else
        puts("\nOs n�meros s�o iguais.");
}

Byte maiorNoVetor(Byte* vetor, Byte tamanho)
{
	Byte maior = 0, indice = 0;

	for ( indice = 0; indice < tamanho; indice++ )
    {
		if ( vetor[indice] > maior )
        {
			maior = vetor[indice];
        }
	}

	return maior;
}

void gerarVetor(void)
{
	srand(time(NULL));

	const Byte TAMANHO = 10, LIMITE_RANDOMICO = 101;
	Byte vetor[TAMANHO], indice = 0;

	puts("\nVetor gerado:");

	for ( indice = 0; indice < TAMANHO; indice++ )
    {
		vetor[indice] = rand() % LIMITE_RANDOMICO;

        printf("%.2d - ", vetor[indice]);
	}

	printf("\nO maior valor presente no vetor �: %.2d", maiorNoVetor(vetor, TAMANHO));
}

int main(void)
{
	setlocale(LC_ALL, "");

	Byte opcao = 0;

	printf(
        "Escolha uma op��o:"
		"\n1. Brincar com N�meros | 2. Gerar um Vetor"
		"\nOp��o? "
    );
	scanf("%hhu", &opcao);

	if ( opcao == 1 )
		brincarComNumeros();
	else if ( opcao == 2 )
		gerarVetor();
	else
		puts("Op��o inv�lida!!");

	return EXIT_SUCCESS;
}