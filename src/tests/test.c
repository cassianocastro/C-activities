#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * Fills a vector with non-repeating numbers
 */
void fillVectorWithNonRepeatingNumbers(int* vector, const int size)
{
	srand(time(NULL));

    int x = 0;

    for ( register int i = 0; i < size; ++i )
	{
		x = 0;

        for ( register int j = 0; j <= i; ++j )
		{
            if ( vector[i - j] == x )
            {
                x = rand() % size;
                j = 0;
            }
        }

		vector[i] = x;
	}
}

/**
 *
 */
unsigned int getStringSize(char* const str)
{
    unsigned int size = 0u;

    while ( str[size] != '\0' )
    {
        ++size;
    }

    return size;
}

/**
 *
 */
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
    {
        char str[100];

        printf("Your string: ");
        scanf(" %[A-Za-z0-9]s", str);

        reverseString(str);

        printf("Reversed string: %s\n", str);
    }

    {
        int size = 10, vector[size];

        fillVectorWithNonRepeatingNumbers(vector, size);

        for ( register int i = 0; i < 10; ++i )
        {
            printf("%d ", vector[i]);
        }

        puts("\n");
    }

    return EXIT_SUCCESS;
}