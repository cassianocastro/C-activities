#include <iso646.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int recursive(int number)
{
    if ( ( number == 1 ) or ( number == 0 ) )
    {
        return 1;
    }

    return number * recursive(number - 1);
}

int iterative(int number)
{
    int fatorial = 1;

    for ( ; number > 1; number-- )
	{
        fatorial *= number;
    }

    return fatorial;
}

/**
 *
 */
int main(int argc, const char** argv)
{
    unsigned int number = 0u, option = 0u;

    printf("Insira um número para o qual deseja calcular seu fatorial: ");
    scanf("%1d", &number);

    printf(
        "Selecione a forma de calcular:\n"
        "1. Iterativa | 2. Recursiva\n"
        "Opção\? "
    );
    scanf("%1d", &option);

    printf(
        "\nFatorial calculado: %d\n",
        ( option == 1 ) ? iterative(number) : recursive(number)
    );

    return EXIT_SUCCESS;
}