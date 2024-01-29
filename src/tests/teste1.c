#include <inttypes.h>
#include <stdio.h>
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
int canGetBits(int numero)
{
    int quociente = 0, bits = 0, resto[10] = { 0 };

    quociente = numero / 2;
    resto[0]  = numero % 2;

    int i = 0;

    for ( i = 1; quociente >= 2; i++ )
	{
        resto[i] = quociente % 2;

        quociente /= 2;
    }

    resto[i] = quociente;

    for ( int j = 9; j >= 0; j-- )
	{
        printf("%i - ", resto[j]);
    }

    printf("\n");

	for ( register int i = 0; i < 8; ++i )
	{
        if ( resto[i] == 1 )
        {
            ++bits;
        }
    }

    return bits;
}

/**
 *
 */
int main(int argc, const char** argv)
{
    setlocale(LC_ALL, "");

    int number = 0;

    printf("Digite um numero: ");
    scanf("%d", &number);

    printf("%d", canGetBits(number));

    return 0;
}