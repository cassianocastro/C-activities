#include <inttypes.h>
#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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
        printf("O maior número é: %d", response);
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

void gerarVetor(void)
{
	srand(time(NULL));

	const byte TAMANHO = 10, LIMITE_RANDOMICO = 101;
	byte vetor[TAMANHO];

	puts("\nVetor gerado:");

	for ( register byte i = 0; i < TAMANHO; ++i )
    {
		vetor[i] = rand() % LIMITE_RANDOMICO;

        printf("%.2d - ", vetor[i]);
	}

	printf("\nO maior valor presente no vetor é: %.2d", maiorNoVetor(vetor, TAMANHO));
}

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
		gerarVetor();
	else
		puts("Opção inválida!");

	return EXIT_SUCCESS;
}