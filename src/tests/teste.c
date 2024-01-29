#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <time.h>

void foo(void)
{
	srand(time(NULL));

    int vetor[10], x = 0, cont = 0;

    for ( int i = 0; i < 10; i++ )
	{
		cont = 0;
		x    = 0;

		// do {
		// 	if ( vetor[i - cont] == x )
        //  {
		// 		x = rand() % 10;
		// 		cont = 0;
		// 	} else
		// 		cont++;
		// } while ( cont <= i );

        for ( int j = 0; j <= i; j++ )
		{
            if ( vetor[i - j] == x )
            {
                x = rand() % 10;
                j = 0;
            }
        }

		vetor[i] = x;

		printf("%d - ", vetor[i]);
	}
}

/**
 *
 */
int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "");

    char nome[100], foo[100];

    int size = 0;

    printf("Digite uma palavra: ");
    gets(nome);

    while ( nome[size] != '\0' )
    {
        size++;
    }

    printf("\n%i\n", size);

    for ( int i = 0, j = size; i <= size / 2; i++, j-- )
	{
        foo[i] = nome[j];
    }

    printf("%s", foo);
    //printf("%i", strlen(nome));

    return 0;
}