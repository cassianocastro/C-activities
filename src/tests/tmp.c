#include <iso646.h>
#include <stdio.h>

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