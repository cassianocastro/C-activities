#include <inttypes.h>
#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

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

	printf("\nDigite um número: ");
	scanf("%d", &a);

	printf("Outro...: ");
	scanf("%d", &b);

	maior(a, b, &resposta);

	if ( resposta not_eq 0 )
        printf("O maior número é: %d", resposta);
    else
        puts("\nOs números são iguais.");
}

byte maiorNoVetor(byte* vetor, byte tamanho)
{
	byte maior = 0, indice = 0;

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

	const byte TAMANHO = 10, LIMITE_RANDOMICO = 101;
	byte vetor[TAMANHO], indice = 0;

	puts("\nVetor gerado:");

	for ( indice = 0; indice < TAMANHO; indice++ )
    {
		vetor[indice] = rand() % LIMITE_RANDOMICO;

        printf("%.2d - ", vetor[indice]);
	}

	printf("\nO maior valor presente no vetor é: %.2d", maiorNoVetor(vetor, TAMANHO));
}

int main(void)
{
	setlocale(LC_ALL, "");

	byte opcao = 0;

	printf(
        "Escolha uma opção:"
		"\n1. Brincar com Números | 2. Gerar um Vetor"
		"\nOpção\? "
    );
	scanf("%hhu", &opcao);

	if ( opcao == 1 )
		brincarComNumeros();
	else if ( opcao == 2 )
		gerarVetor();
	else
		puts("Opção inválida!");

	return EXIT_SUCCESS;
}