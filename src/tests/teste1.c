#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/**
 * @test
 */
void canAlignOutput(void)
{
	int value = 1;

    printf("Justificado a direita  => %5d\n", value);
    printf("Justificado a esquerda => %-5d\n", value);

	uint_fast8_t fast = 190;

	// printf("Poder: %hhu\nSizeof: %hhu", fast, sizeof(uint_fast8_t));
}

/**
 * @test
 */
void canInputUser(void)
{
    #define STR_SIZE 10

    char name[STR_SIZE], surname[STR_SIZE], format[50];

    sprintf(format, " %%%d[A-Za-z] %%%d[A-Za-z]", STR_SIZE - 1, STR_SIZE - 1);

    // printf("%s\n", format);

    printf("Name: ");
    scanf(format, name, surname);

    printf("Your name: %s %s\n", name, surname);
}

/**
 * @test
 */
int canGetBits(int number, int* vector)
{
    int i = 0;

	while ( number >= 2 )
    {
        vector[i] = number % 2;

        number /= 2;

        ++i;
    }

    vector[i] = number;

    for ( int j = 7; j >= 0; j-- )
	{
        printf("%i ", vector[j]);
    }

    printf("\n");

    int count = 0;

	for ( register int i = 0; i < 8; ++i )
	{
        if ( vector[i] == 1 )
        {
            ++count;
        }
    }

    return count;
}

/**
 *
 */
int main(int argc, const char** argv)
{
    setlocale(LC_ALL, "");

    int number = 0, bits[8] = { 0 };

    printf("Digite um numero: ");
    scanf("%d", &number);

    printf("Número de bits 1: %d\n", canGetBits(number, bits));

    return 0;
}