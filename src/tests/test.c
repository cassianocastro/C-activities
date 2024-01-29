#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

unsigned int getStringSize(char* const str)
{
    unsigned int size = 0u;

    while ( str[size] != '\0' )
    {
        ++size;
    }

    return size;
}

void reverseString(char* str)
{
    char buffer[100];

    unsigned int size = getStringSize(str);

    for ( register int i = 0, j = size - 1; i <= size; ++i, --j )
    {
        buffer[i] = str[j];
    }

    strcpy(str, buffer);
}

/**
 *
 */
int main(int argc, const char** argv)
{
    char str[100];

    printf("Your string: ");
    scanf(" %[A-Za-z0-9]s", str);

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return EXIT_SUCCESS;
}