#include <stdio.h>
#include <string.h>
#include <locale.h>

int getBits(int numero)
{
    int resto[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int quociente, qtdeBits = 0;

    quociente = numero / 2;
    resto[0]  = numero % 2;

    int i = 0;

    for ( i = 1; quociente >= 2; i++ )
	{
        resto[i]   = quociente % 2;
        quociente /= 2;
    }
    printf("%i\n", i);
    resto[i] = quociente;

    for( int j = 9; j >= 0; j-- )
	{
        printf("%i - ", resto[j]);
    }

    /*
	for ( int i = 0; i < 8; i++ )
	{
        if ( resto[i] == 1 ) {
            qtdeBits++;
        }
    }
	*/
    return qtdeBits;
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");

    int numero = 0, bits = 0;

    printf("Digite um numero: ");
    scanf("%i", &numero);

    bits = getBits(numero);
    //printf("%i", bits);
    return 0;
}